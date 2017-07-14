//linked list interface 

#ifndef _linkedList_

#define _linkedList_

class Node{
	int n;
	Node * NextNodePtr=NULL;
public:
	Node(int );
	~Node():
}

class LinkedList{
	
	Node * initPtr;
	Node * finPtr;
		

public :
	LinkedList();
	~LinkedList():
	void add(int  ) ; 
	void remove(int  );
	int get (int);
	void set (int , int);








#endif
