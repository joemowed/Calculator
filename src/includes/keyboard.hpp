#ifndef keyboard_INC_GRD
#define keyboard_INC_GRD
#include "main.h"
#include <array>
#include <ringbuffer.hpp>
class Keyboard {
  private:
    // keyboard is polled every 3ms, debounce time = (3*DEBOUNCE_COUNT)ms, e.g. for 80ms debounce use 26
    constexpr static const uint16_t DEBOUNCE_COUNT = 100; // The number of times the IRQ can read the key as high before the key will be registered as pressed again
    // repeat time for a held key to register as repeated keypresses is (polling time)(DEBOUNCE_COUNT)(KEY_REPEAT_DELAY), e.g. 3ms*26*5 = 400ms repeat delay
    constexpr static const uint16_t KEY_REPEAT_DELAY = 4;
    constexpr static const std::size_t BUFFER_SIZE = 200;

  public:
    const struct keyCodes {
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
    } keyCodes;

    typedef struct KeyHALPair {
        GPIO_TypeDef *port;
        uint16_t pin;
    } KeyHALPair;

    typedef struct Key {
        KeyHALPair HAL;
        uint16_t debounceCount;
        uint16_t repeatCount;
        bool wasPressed;
        char keyChar;
    } Key;
    // gets the oldest key input from buffer, removes the read element from the buffer
    char read();
    // reads all the keys, and writes the new keypresses to buffer.  Multiple keypresses are handled by writing them in the order of the the below array, ascending
    void readAllKeys();

  private:
    // reads GPIO for keypresses, handles debouncing
    void readKey(Key &key);
    // writes keypresses to the keyboard ringbuffer, handles the key repeat delay
    void writeKey(Key &key);
    RingBuffer<char, BUFFER_SIZE> rb = RingBuffer<char, BUFFER_SIZE>(Keyboard::keyCodes.NULLKEY);
    uint16_t bufferLength = 0; // number of valid data elements in buffer
    std::array<char, 1024> keyBuffer;
    std::array<Key, 21> keys = {{
        {{KEY_F1_GPIO_Port, KEY_F1_Pin}, 0, 0, false, keyCodes.F1},
        {{KEY_F2_GPIO_Port, KEY_F2_Pin}, 0, 0, false, keyCodes.F2},
        {{KEY_F3_GPIO_Port, KEY_F3_Pin}, 0, 0, false, keyCodes.F3},
        {{KEY_F4_GPIO_Port, KEY_F4_Pin}, 0, 0, false, keyCodes.F4},
        {{KEY_0_GPIO_Port, KEY_0_Pin}, 0, 0, false, '0'},
        {{KEY_1_GPIO_Port, KEY_1_Pin}, 0, 0, false, '1'},
        {{KEY_2_GPIO_Port, KEY_2_Pin}, 0, 0, false, '2'},
        {{KEY_3_GPIO_Port, KEY_3_Pin}, 0, 0, false, '3'},
        {{KEY_4_GPIO_Port, KEY_4_Pin}, 0, 0, false, '4'},
        {{KEY_5_GPIO_Port, KEY_5_Pin}, 0, 0, false, '5'},
        {{KEY_6_GPIO_Port, KEY_6_Pin}, 0, 0, false, '6'},
        {{KEY_7_GPIO_Port, KEY_7_Pin}, 0, 0, false, '7'},
        {{KEY_8_GPIO_Port, KEY_8_Pin}, 0, 0, false, '8'},
        {{KEY_9_GPIO_Port, KEY_9_Pin}, 0, 0, false, '9'},
        {{KEY_NUM_GPIO_Port, KEY_NUM_Pin}, 0, 0, false, keyCodes.NUM},
        {{KEY_RTN_GPIO_Port, KEY_RTN_Pin}, 0, 0, false, keyCodes.RTN},
        {{KEY_DIV_GPIO_Port, KEY_DIV_Pin}, 0, 0, false, keyCodes.DIV},
        {{KEY_MUL_GPIO_Port, KEY_MUL_Pin}, 0, 0, false, keyCodes.MUL},
        {{KEY_SUB_GPIO_Port, KEY_SUB_Pin}, 0, 0, false, keyCodes.SUB},
        {{KEY_ADD_GPIO_Port, KEY_ADD_Pin}, 0, 0, false, keyCodes.ADD},
        {{KEY_DEL_GPIO_Port, KEY_DEL_Pin}, 0, 0, false, keyCodes.DEL},
    }};
};

#endif
