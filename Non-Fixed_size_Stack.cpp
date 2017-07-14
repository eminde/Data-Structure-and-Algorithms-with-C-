//Non-Fixed_size_Stack.cpp
//Non-fixed size Generic Stack Implementation
//12 Jul 2017 
//ACM Assignment
//Written by ADM 


using namespace std; 


template <typename T>
Node::Node<T>(const T &  n){
		ptr = nullptr;
		value = n;
}


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
