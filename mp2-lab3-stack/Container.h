#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container {
    T* pMem;
    int size;
    int capacity;
public:
    // Конструктор по умолчанию — размер 100
    Container(int _size = 100) {
        size = 0;
        capacity = _size;
        pMem = new T[capacity];
    }

    Container(const Container& other) {
        size = other.size;
        capacity = other.capacity;
        pMem = new T[other.capacity];
        for (int i = 0; i < size; ++i) {
            pMem[i] = other.pMem[i];
        }
    }

    Container& operator=(const Container& other) {
        if (this != &other) {
            size = other.size;
            capacity = other.capacity;
            delete[] pMem;
            pMem = new T[capacity];
            for (int i = 0; i < size; i++) {
                pMem[i] = other.pMem[i];
            }
        }
        return *this;
    }

    ~Container() {
        delete[] pMem;
    }

    T& operator[](int index) {
        if (index >= size || index < 0) {
            throw "err";
        }
        return pMem[index];
    }

    const T& operator[](int index) const {
        if (index >= size || index < 0) {
            throw "err";
        }
        return pMem[index];
    }

    void push_back(const T& value) {
        pMem[size++] = value;
    }

    int get_size() {
        return size;
    }

    // Очистка контейнера
    void clear() {
        size = 0;
    }
};

#endif
