#include <keyboard.hpp>
#include <main.h>

char Keyboard::read() { return this->rb.readData(); }
void Keyboard::readAllKeys() {
    for (Key &key : this->keys) {
        this->readKey(key);
    }
}
void Keyboard::readKey(Key &key) {
    bool isPressed = HAL_GPIO_ReadPin(key.HAL.port, key.HAL.pin);
    if (isPressed && (key.debounceCount == 0)) {
        this->rb.writeData(key.keyChar);
        key.debounceCount = this->DEBOUNCE_COUNT;
    }
    key.debounceCount = (key.debounceCount > 0) ? (key.debounceCount - 1) : 0;
}
