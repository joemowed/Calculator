#ifndef keyboard_INC_GRD
#define keyboard_INC_GRD
#include "main.h"
#include <array>
#include <ringbuffer.hpp>
// helper class for the keyboard
class Key {
  public:
    struct KeyHALPair {
        GPIO_TypeDef *port;
        uint16_t pin;
    } keyHALPair;
    uint16_t repeatCounter = 0;
    uint32_t readHistory = 0;
    const char keyChar;
    Key(struct KeyHALPair keyHalPair, const char keyChar);
    // polls the output, performs the debouncing, and calculates if the keypress is held and to be repeated
    // returns NULLKEY if the key is either not pressed, or not yet ready to emit again
    char poll();

  private:
    // puts the read into the readhistory
    void tick(volatile const bool &isPressed);
    // helper function, emits the keyChar if the key repeat delay allows for a keypress, otherwise emits nullkey
    char keyRepeat();
};
class Keyboard {
  private:
    constexpr static const std::size_t BUFFER_SIZE = 200;

  public:
    // repeat time for a held key to register as repeated keypresses is (polling time)(KEY_REPEAT_DELAY), e.g. 3ms*133 = 399ms repeat delay
    constexpr static const uint16_t KEY_REPEAT_DELAY = 200;
    struct KeyCodes {
        const char F1 = 0x1;      // character code for "F1" key
        const char F2 = 0x2;      // character code for "F2" key
        const char F3 = 0x3;      // character code for "F3" key
        const char F4 = 0x4;      // character code for "F4" key
        const char NUM = 0x5;     // character code for "NUM" key
        const char RTN = 0x6;     // character code for "RTN" key
        const char DIV = '/';     // character code for "DIV" key
        const char MUL = '*';     // character code for "MUL" key
        const char SUB = '-';     // character code for "SUB" key
        const char ADD = '+';     // character code for "ADD" key
        const char DEL = '.';     // character code for "DEL" (decimal) key
        const char NULLKEY = 0x7; // character code to return when the key buffer is empty
    } constexpr static const keyCodes = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, '/', '*', '-', '+', '.', 0x7};

    // gets the oldest key input from buffer, removes the read element from the buffer
    char read();
    // reads all the keys, and writes the new keypresses to buffer.  Multiple keypresses are handled by writing them in the order of the the below array, ascending
    void readAllKeys();

  private:
    // reads GPIO for keypresses, handles debouncing
    void readKey(Key &key);
    RingBuffer<char, BUFFER_SIZE> rb = RingBuffer<char, BUFFER_SIZE>(Keyboard::keyCodes.NULLKEY);
    uint16_t bufferLength = 0; // number of valid data elements in buffer
    std::array<char, 1024> keyBuffer;
    std::array<Key, 21> keys = {
        Key{{KEY_F1_GPIO_Port, KEY_F1_Pin}, keyCodes.F1},
        Key{{KEY_F2_GPIO_Port, KEY_F2_Pin}, keyCodes.F2},
        Key{{KEY_F3_GPIO_Port, KEY_F3_Pin}, keyCodes.F3},
        Key{{KEY_F4_GPIO_Port, KEY_F4_Pin}, keyCodes.F4},
        Key{{KEY_0_GPIO_Port, KEY_0_Pin}, '0'},
        Key{{KEY_1_GPIO_Port, KEY_1_Pin}, '1'},
        Key{{KEY_2_GPIO_Port, KEY_2_Pin}, '2'},
        Key{{KEY_3_GPIO_Port, KEY_3_Pin}, '3'},
        Key{{KEY_4_GPIO_Port, KEY_4_Pin}, '4'},
        Key{{KEY_5_GPIO_Port, KEY_5_Pin}, '5'},
        Key{{KEY_6_GPIO_Port, KEY_6_Pin}, '6'},
        Key{{KEY_7_GPIO_Port, KEY_7_Pin}, '7'},
        Key{{KEY_8_GPIO_Port, KEY_8_Pin}, '8'},
        Key{{KEY_9_GPIO_Port, KEY_9_Pin}, '9'},
        Key{{KEY_NUM_GPIO_Port, KEY_NUM_Pin}, keyCodes.NUM},
        Key{{KEY_RTN_GPIO_Port, KEY_RTN_Pin}, keyCodes.RTN},
        Key{{KEY_DIV_GPIO_Port, KEY_DIV_Pin}, keyCodes.DIV},
        Key{{KEY_MUL_GPIO_Port, KEY_MUL_Pin}, keyCodes.MUL},
        Key{{KEY_SUB_GPIO_Port, KEY_SUB_Pin}, keyCodes.SUB},
        Key{{KEY_ADD_GPIO_Port, KEY_ADD_Pin}, keyCodes.ADD},
        Key{{KEY_DEL_GPIO_Port, KEY_DEL_Pin}, keyCodes.DEL},
    };
};
#endif
