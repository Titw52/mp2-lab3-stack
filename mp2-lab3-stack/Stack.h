#ifndef __Stack_H__
#define __Stack_H__

#include <iostream>

using namespace std;

template<typename T>
class Stack
{
protected:
    int topIndex, size;
    T* pMem;
public:
    Stack(int _size = 10) {
        if (_size < 0) throw "err";
        pMem = new T[_size];
        size = _size;
        topIndex = -1;
    }
    ~Stack() {
        delete[] pMem;
    }
    Stack(const Stack& s) {
        size = s.size;
        topIndex = s.topIndex;
        pMem = new T[size];
        for (int i = 0; i < topIndex; i++) {
            pMem[i] = s.pMem[i];
        }
    }
    Stack(const Stack&& s) {
        size = s.size;
        topIndex = s.topIndex;
        pMem = s.pMem;
        s.size = 0;
        s.topIndex = 0;
        s.pMem = nullptr;
    }


    Stack<T>& operator=(const Stack<T>& s) {
        if (this != &s) {
            size = s.size;
            topIndex = s.topIndex;
            delete[] pMem;
            pMem = new T[size];
            for (int i = 0; i < topIndex; i++) {
                pMem[i] = s.pMem[i];
            }
        }
        return *this;
    }
    Stack<T>& operator=(const Stack<T>&& s) {
        if (this != &s) {
            size = s.size;
            topIndex = s.topIndex;
            delete[] pMem;
            pMem = s.pMem;
            s.size = 0;
            s.topIndex = 0;
        }
        return *this;
    }

    bool operator==(const Stack<T>& s) {
        if (size != s.size || topIndex != s.topIndex) {
            return false;
        }
        for (int i = 0; i < topIndex; i++) {
            if (pMem[i] != s.pMem[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Stack<T>& s) {
        return !operator==(s);
    }

    bool isFull(){
        return topIndex == size - 1;
    }
    bool isEmpty() {
        return topIndex == -1;
    }
    bool clean() {
        topIndex = -1;
    }
    
    void push(T elem) {
        if (isFull()) {
            throw "err";
        }
        topIndex++;
        pMem[topIndex] = elem;
    }
    T pop() {
        if (isEmpty()) {
            throw "err";
        }
        topIndex--;
        return pMem[topIndex + 1];
    }
};

#endif
