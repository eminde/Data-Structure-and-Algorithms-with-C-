//Non-Fixed_size_Stack.cpp
//Non-fixed size Generic Stack 
//12 Jul 2017 
//ACM Assignment
//Written by ADM 

#include <exception>


using namespace std; 

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
Node::Node<T>(const T &  n){
		ptr = nullptr;
		value = n;
}

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

template <typename T>
Stack<T>::~Stack(){
	if(isEmpty()){return}
	while(_size ){
	Node<T> * tempPtr = nodePtr;
	nodePtr = nodePtr->ptr;
	delete tempPtr;
	_size--;
 	}
}

template <typename T>
void Stack<T>::push(T n ){
	if (isEmpty()){
		nodePtr=new Node<T>(n);
		_size = 1;
	}
	Node<T>  * tempPtr = new Node<T>(n);
	tempPtr->ptr = nodePtr;
	nodePtr = tempPtr;
	_size++;
}

template <typename T>
T Stack<T>::pop(){
	if(isEmpty()) throw E("stack empty");
	T n = nodePtr->value;
	Node *tempPtr= nodePtr;
	nodePtr = tempPtr->ptr;
	delete tempPtr;
	_size--;
	return n ;
}

template <typename T>
T & Stack<T>::topValue(){
	return nodePtr->value;
}	
