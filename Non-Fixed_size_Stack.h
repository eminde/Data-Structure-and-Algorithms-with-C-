//Non-Fixed_size_Stack.h
//Non-fixed size Generic Stack InterFace
//12 Jul 2017 
//ACM Assignment
//Written by ADM 

#ifndef _Stack_

#define _Stack_


#include <exception>



class E:public exception{
	const char * msg;
	E(){};// no default constructor
public:
	explicit E (const char * s)throw():msg(s){} // prevents from unwanted type cast during construction
	const char * what ()const throw(){return msg;}
};

template <typename T>
class Node{
	Node * ptr;
	T value;
	Node(){};
public:
	Node(const T & );
friend class Stack<T>;
};


template <typename T>
class Stack {
	Node<T> * nodePtr;
	int _size;

public:
	Stack():nodePtr(nullptr),_size(0){}
	~Stack();
	void push(const T & );
	T pop();
	T& topValue();
    int size() const { return _size; }
	bool isEmpty() const { return _size == 0 ; }
};	

#endif