//LinkedList.cpp
//
//ACM Assignment
//ADTs
//Written By ADM



//Class Node Constructor
Node::Node(int v ) {
	n=v;
	nextNodePtr=NULL;
}

//Overloading = operator for Class Node
Node &  Node::operator = (int n ) {
	this.n = n ;
	return *this;
}

//Class linked list  constructor
LinkedList::LinkedList(){
	intiPtr = new Node();
	finPtr = initPtr;
}

LinkedList::~LinkedList(){
	Node * iteratorPtr = initPtr;
	while(itretorPtr != finPtr){
		Node *temp = iteratorPtr;
		this.iterate(iteratorPtr, 1);
		delete temp;
	}
	delete finPtr;
}


void LinkedList::add(int n ) {
	finPtr->nextNodePtr=new Node(n);
	finPtr=finPtr->nextNodePtr;
}


void LinkedList::remove(int n ){

	Node * iteratorPtr =this.iterate(*new Node* (initPtr),n-1);
	if(!iteratorPtr) return;
	Node *prePtr =iteratorPtr;
	Node *ptr = this.iterate(iteratorPtr,1);
	if(!iteratorPtr)return;
	Node *postPtr = this.iterate(iteratorPtr,1);
	if(!iteratorPtr)return;
	delete ptr;	
	prePtr->nextNodePtr = postPtr;
}

Node *  LinkedList::iterate(Node * ptr, int n ){

	for(int i = 0 ; i<n ; i++)
		if (ptr->nextNodePtr)	ptr=ptr->nextNodePtr;		
}

int  &   LinkedList::operator[] (int n)const {
	Node * iteratorPtr=initPtr;
	this.iterate(iteratorPtr, n)
	return &iteratroPtr->n;
}

Node *  LinkedList::search(int n){
	Node * iteratorPtr = initPtr;
	while(iteratorPtr!=finPtr){
		this.iterate(iteratorPtr, 1);
		if (iteratorPtr->n== n )break;
		return initPtr;
	}
	return iteratorPtr;
}
