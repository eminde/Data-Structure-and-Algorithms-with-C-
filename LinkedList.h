//LinkedList.h
//LinkedList interface 
//
//ACM Assignment
//ADTs
//Written By ADM


#ifndef _linkedList_

#define _linkedList_

class Node{
	int n;
	Node * NextNodePtr=NULL;
	Node(){}
public:
	Node(int );
	~Node():
	Node & operator = (int );
};

class LinkedList{
	
	Node * initPtr;
	Node * finPtr;
		

public :
	LinkedList();
	~LinkedList():
	void add(int); 
	void remove(int);
	Node * iterate(Node *, int);
	int  &   operator[] (int);
	Node *  search(int );
	//add insert to end
	
};


#endif
