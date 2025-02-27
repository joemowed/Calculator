#include <keyboard.hpp>
#include <main.h>

Key::Key(struct KeyHALPair keyHalPair, const char keyChar) : keyHALPair(keyHalPair), keyChar(keyChar) {}

void Key::tick(volatile const bool &isPressed) {
    this->readHistory <<= 1;
    if (isPressed) {
        this->readHistory |= static_cast<uint32_t>(1U);
    }
}

char Key::poll() {
    // logic low is a pressed key
    volatile const bool isPressed = !HAL_GPIO_ReadPin(this->keyHALPair.port, this->keyHALPair.pin);
    // return the nullkey by default
    char ret = Keyboard::keyCodes.NULLKEY;
    if (isPressed) {
        if (this->readHistory == UINT32_MAX) {
            // do the key repeat algo here
            ret = this->keyRepeat();
        } else if (this->readHistory == 0U) {
            ret = this->keyChar;
        }
    }
    this->tick(isPressed);
    return ret;
}

char Key::keyRepeat() {
    bool repeatValid = this->repeatCounter == Keyboard::KEY_REPEAT_DELAY;
    this->repeatCounter = (repeatValid) ? 0 : (this->repeatCounter + 1);
    return (repeatValid) ? this->keyChar : Keyboard::keyCodes.NULLKEY;
}

char Keyboard::read() { return this->rb.readData(); }
void Keyboard::readAllKeys() {
    for (Key &key : this->keys) {
        this->readKey(key);
    }
}
void Keyboard::readKey(Key &key) {
    // logic low for pressed keys
    const char tmp = key.poll();
    if (tmp != this->keyCodes.NULLKEY) {
        this->rb.writeData(tmp);
    }
}
