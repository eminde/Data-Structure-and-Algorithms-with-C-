//Fixed-Size_Stack.cpp
//fixed-size Generic  Stack 
//14 july 2017
//ACM Assignment
//Written by ADM

#include <exception>

using namespace std;

template <typename T>
Stack<T>::Stack ( int s ) {
    if(s > maxSize || s < 1) throw E("invalid stack size");
    else _size = s;
    stackPtr = new T[_size];
    _top = -1;
}


Stack::~Stack() { delete[] stackPtr; }


template <typename T>
T & Stack<T>::push ( const T & i ) {
    if(isFull()) throw E("stack full");
    return stackPtr[++_top] = i;
}

template <typename T>
void Stack<T>::pop () {
    if(isEmpty()) throw E("stack empty");
    stackPtr[_top--];
}

template <typename T>
T & Stack<T>::topValue(){
    return stackPtr[_top];
}

bool Stack::isEmpty() const { return _top < 0; }

bool Stack::isFull() const { return _top >= _size - 1; }

int Stack::top() const { return _top; }
int Stack::size() const { return _size; }