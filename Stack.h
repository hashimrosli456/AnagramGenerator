#include <iostream>
using namespace std;
//Stack.h

template <class T>
class stackNode{
	public:
 		T value; // Node value
 		stackNode<T> *next; // Pointer to the next node
 		// Constructor
 		stackNode (T nodeValue){ 
		 	value = nodeValue;
 			next = NULL;}
};

template <class T>
class stack {
	private:
 		stackNode <T> *stackTop;
 		int count;
	public:
 		T Top(); // return top value of the stack
 		void Pop(); //delete the top of the stack
 		void Push(T); //add new data to the stack
 		bool IsEmptyStack();
 		int numStackNode(){
 			return count;}
 		void destroyStack();//delete all nodes in the stack
 		void CopyStack(stack<char> );
 		void SwapStack(int,int);
 		void moveTopToBottom();
 		stack();
 		~stack();
};

template <class T>
stack <T> ::stack(){
	stackTop=NULL;
	count=0;
}

template <class T>
stack <T> ::~stack(){
	destroyStack();
}

template <class T>
T stack <T> ::Top(){
	if (!IsEmptyStack())
 	return stackTop->value;
}

template <class T>
void stack <T> ::Pop(){
 	stackNode<T> *nodePtr;
 	if (IsEmptyStack())
 		cout <<"Stack is Empty...\n";
 	else {
 		nodePtr=stackTop;
 		stackTop=stackTop->next;
 		delete nodePtr;
 		count--;
 	}
}

template <class T>
void stack <T> ::Push(T newValue){
 	stackNode<T> *newNode;
 	newNode = new stackNode<T>(newValue);
 	if (stackTop==NULL) //if (IsEmptyStack()
 		stackTop=newNode;
 	else {
 		newNode->next=stackTop;
 		stackTop=newNode;
 		count++;
 	}
}

template <class T>
bool stack <T> ::IsEmptyStack() {
 	if (stackTop==NULL)
 		return true;
 	else
 		return false;
}
 
template <class T>
void stack <T> ::CopyStack(stack<char> Stack) {
	stack<T> tempStack;
 	if(Stack.IsEmptyStack())
 		cout<<"Stack Empty !"<<endl;
 	else{
 		while(!Stack.IsEmptyStack()){
 			tempStack.Push(Stack.Top());
 			Stack.Pop();
		}
		while(!tempStack.IsEmptyStack()){
 			Push(tempStack.Top());
 			tempStack.Pop();
		}
	}
 }
 template <class T>
void stack <T> ::SwapStack(int first,int sec) {
	stack<char> tempStack,tempStack1;
	int i=0;
	while(!IsEmptyStack()){
		if(i>sec)
			break;
		if(i==first){
			tempStack1.Push(Top());
			Pop();
		}
		else{
			tempStack.Push(Top());
			Pop();
		}
		i++;
	}
	Push(tempStack1.Top());
	tempStack1.Pop();
	tempStack1.Push(tempStack.Top());
	tempStack.Pop();
	if(!tempStack.IsEmptyStack()){
		while(!tempStack.IsEmptyStack()){
			Push(tempStack.Top());
			tempStack.Pop();
		}
	}
	Push(tempStack1.Top());
	tempStack1.Pop();
}
template <class T>
void stack <T> ::moveTopToBottom(){
	stack<char> tempStack,tempStack1;
	tempStack1.Push(Top());
	Pop();
	while(!IsEmptyStack()){
		tempStack.Push(Top());
		Pop();
	}
	Push(tempStack1.Top());
	tempStack1.Pop();
	while(!tempStack.IsEmptyStack()){
		Push(tempStack.Top());
		tempStack.Pop();
	}
}
template <class T>
void stack <T> ::destroyStack() {
 	stackNode <T> *nodePtr;
 	while (!IsEmptyStack()) { //while (stackTop!=NULL)
 		nodePtr=stackTop;
 		stackTop=stackTop->next;
 		delete nodePtr;
 	}
 }
