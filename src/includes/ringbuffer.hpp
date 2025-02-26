#include <array>
#include <cstddef>
template <typename T, std::size_t N> class RingBuffer {
  private:
    std::array<T, N> data;
    T *writePtr = data.data();
    T *readPtr = data.data();
    const T *endPtr = this->writePtr + N - 1;
    const T nullValue;
    std::size_t len = 0;
    void incrementPtr(T *&ringBuffPtr) {
        if (ringBuffPtr == this->endPtr) {
            ringBuffPtr = this->data.data();
        } else {
            ringBuffPtr++;
        }
    }

  public:
    // nullValue -- A object of type T that will be returned by the ringbuffer when a read is requested but the buffer is empty
    RingBuffer(T nullValue) : nullValue(nullValue) {}
    // when buffer is full, starts overwriting exisiting buffer from the begining (oldest value in buffer replaced by newest)
    void writeData(const T &value) {
        if (this->len < N) {
            this->len++;
        }
        *(this->writePtr) = value;
        this->incrementPtr(this->writePtr);
    }
    T readData() {
        if (this->len > 0) {
            this->len--;
        } else {
            return this->nullValue;
        }
        T ret = *(this->readPtr);
        this->incrementPtr(this->readPtr);
        return ret;
    }
};
