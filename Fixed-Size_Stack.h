//Fixed-Size_Stack.h
//fixed-size Generic  Stack 
//14 july 2017
//ACM Assignment
//Written by ADM

#ifndef _Stack_

#define _Stack_

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
    bool isEmpty() const ;
    bool isFull() const ;
    int top() const ;
    int size() const ;
};

#endif