#include <keyboard.hpp>
#include <main.h>

char Keyboard::read() { return this->rb.readData(); }
void Keyboard::readAllKeys() {
    for (Key &key : this->keys) {
        this->readKey(key);
    }
}
void Keyboard::readKey(Key &key) {
    // logic low for pressed keys
    bool isPressed = !HAL_GPIO_ReadPin(key.HAL.port, key.HAL.pin);
    if (isPressed && (key.debounceCount == 0)) {
        this->writeKey(key);
        key.debounceCount = this->DEBOUNCE_COUNT;
    }
    key.debounceCount = (key.debounceCount > 0) ? (key.debounceCount - 1) : 0;
    key.wasPressed = isPressed;
}
void Keyboard::writeKey(Key &key) {
    // if the key was pressed in the last poll, only write the key to the ringbuffer if the repeatCount is at 0
    // always write the key to the ringbuffer if it was not pressed in the last poll
    if (key.wasPressed) {
        if (key.repeatCount == 0) {
            this->rb.writeData(key.keyChar);
            key.repeatCount = this->KEY_REPEAT_DELAY;
        } else {
            key.repeatCount = (key.repeatCount > 0) ? (key.repeatCount - 1) : 0;
        }
    } else {
        this->rb.writeData(key.keyChar);
    }
}
