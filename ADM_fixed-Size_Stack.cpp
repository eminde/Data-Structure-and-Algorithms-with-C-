//
//fixed-size Generic  Stack 
//14 july 2017
//ACM Assignment
//Written by ADM

#include <exception>


using namespace std;

class E : public exception {
    E(){};  // no default constructor
    const char * msg;
public:
    explicit E(const char * s) throw() : msg(s) { }//"explicit" prevents from unwanted type cast during construction
    const char * what() const throw() { return msg; }
};

    


template <typename T>
class Stack {
private:
    const int defaultSize = 10;
    const int maxSize = 1000;
    int _size;
    int _top;
    T * stackPtr;
public:
    explicit Stack(int s = defaultSize);
    ~Stack() { delete[] stackPtr; }
    void push( const T & );
    T & pop();
    T & topValue();
    bool isEmpty() const { return _top < 0; }
    bool isFull() const { return _top >= _size - 1; }
    int top() const { return _top; }
    int size() const { return _size; }
};

template <typename T>
Stack<T>::Stack ( int s ) {
    if(s > maxSize || s < 1) throw E("invalid stack size");
    else _size = s;
    stackPtr = new T[_size];
    _top = -1;
}

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