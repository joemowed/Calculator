#include <keyboard.hpp>
#include <main.h>
char Keyboard::readBuffer() {
    if (this->bufferLength == 0) {
        return keyCodes.BUFFER_EMPTY;
    }
    char ret = this->keyBuffer[0];
    this->bufferLength--;
    this->reduceBuffer();
    return ret;
}
void Keyboard::reduceBuffer() {
    for (int i = 1; i < this->bufferLength; i++) {
        this->keyBuffer[i - 1] = this->keyBuffer[i];
    }
}
void Keyboard::readAllKeys() {}
void Keyboard::readKey(Key &key) {
    bool isPressed = HAL_GPIO_ReadPin(key.HAL.port, key.HAL.pin);
    if (isPressed) {
        if (key.debounceCount < this->DEBOUNCE_COUNT) {
            // don't read the key if the debounce count is not   w
            key.debounceCount++;
            return;
        }
    }
}
