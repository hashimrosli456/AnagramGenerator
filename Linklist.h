#include <iostream>
using namespace std;
//Linklist.h

template <class T>
class ListNode
{
public:
   	T value;           
   	ListNode<T> *next; 
   	ListNode (T nodeValue){ 
	   	value = nodeValue;
        next = NULL;
	}
};

template <class T>
class LinkedList
{
	private:
   		ListNode<T> *head;  
		int count; 
  
	public:
   		LinkedList(){ head = NULL; count=0;}
   		~LinkedList();
   		void appendNode(T); //to add node 
   		void insertNode(T); //to insert node 
   		void deleteNode(T); //to delete node 
   		void displayList() const; //to display all nodes
   		void CopyList(LinkedList<string> List);
   		int CountNodes(){return count;}
   		void destroyList();
   		void search(char);  
   		bool IsEmptyList();
   		bool Found(T);
   		T firstNode();
};
template <class T>
bool LinkedList<T>::IsEmptyList()
{
   	ListNode<T> *nodePtr;
   	nodePtr=head;
	if(nodePtr!=NULL)
		return true;
	else
		return false;
}
template <class T>
void LinkedList<T>::appendNode(T newValue)
{
   	ListNode<T> *newNode;
   	ListNode<T> *nodePtr;
   	newNode = new ListNode<T>(newValue);

   	if (!head)
      	head = newNode;
   	else  
   	{
      	nodePtr = head;
      	while (nodePtr->next)
         	nodePtr = nodePtr->next;

      	nodePtr->next = newNode;
   	}
   	count++;
}
template <class T>
void LinkedList<T>::displayList() const
{
   	ListNode<T> *nodePtr;  
   	nodePtr = head;
	int i=1;
	nodePtr = nodePtr->next;
   	while (nodePtr){
        cout <<"\n\t\t->"<<i<<". "<< nodePtr->value;
      	nodePtr = nodePtr->next;
      	i++;
   	}
}
template <class T>
T LinkedList<T>::firstNode()
{
   	ListNode<T> *nodePtr;  
   	nodePtr = head;

    return nodePtr->value;
}

template <class T>
void LinkedList<T>::search(char alphabet) 
{
   	ListNode<T> *nodePtr; 
   	bool found=false;
   	nodePtr = head;
   	char w[nodePtr->value.length()];
   	int length=nodePtr->value.length();
   	while(nodePtr){
   		for(int i=0;i<length;i++)
   			w[i]=nodePtr->value[i];
        nodePtr = nodePtr->next;
	}
   	nodePtr = head;
   	while (nodePtr){
     	if(nodePtr->value[0]==alphabet){
        	found=true;
        	cout<<"\t\t-> "<<nodePtr->value<<endl;
		}
        nodePtr = nodePtr->next;
   	}
   	if (!found)
	   cout <<"\n\n\tInfo not found in the list....\n"; 
}
template <class T>
bool LinkedList<T>::Found(T word) 
{
   	ListNode<T> *nodePtr; 
   	bool found=false;
   	nodePtr = head;
   	
   	while (nodePtr &&!found){
     	if(nodePtr->value==word)
        	found=true;
      	else 
           	nodePtr = nodePtr->next;
   	}
	return found;
}
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
   	ListNode<T> *newNode;
   	ListNode<T> *nodePtr;
   	ListNode<T> *previousNode = NULL;
   	newNode = new ListNode<T>(newValue);
   
   	if (!head){
      head = newNode;
      newNode->next = NULL;
   	}
   	else {
      	nodePtr = head;
      	previousNode = NULL;

      	while (nodePtr != NULL && nodePtr->value < newValue){  
         	previousNode = nodePtr;
         	nodePtr = nodePtr->next;
      	}

      	if (previousNode == NULL){
         	head = newNode;
         	newNode->next = nodePtr;
      	}
      	else {
         	previousNode->next = newNode;
         	newNode->next = nodePtr;
      	}
   	}
   	count++;
}
template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
   	ListNode<T> *nodePtr;
   	ListNode<T> *previousNode;

   	if (!head)
      	cout <<"List is Empty\n";
   
   	if (head->value == searchValue){
      	nodePtr=head;
      	head=head->next;
      	delete nodePtr; 
   	}
   	else{
      	nodePtr = head;

      	while (nodePtr != NULL && nodePtr->value != searchValue){  
         	previousNode = nodePtr;
         	nodePtr = nodePtr->next;
      	}

      	if (nodePtr){
         	previousNode->next = nodePtr->next;
         	delete nodePtr;
      	}
   	}
   	count--;
}
template <class T>
void LinkedList<T>::CopyList(LinkedList<string> List)
{
	while(!List.IsEmptyList()){
		appendNode(List.firstNode());
		List.deleteNode(List.firstNode());
	}
}
template <class T>
void LinkedList<T>::destroyList()
{
	ListNode<T> *nodePtr;
   	ListNode<T> *nextNode;
   	nodePtr = head;

   	while (nodePtr){
      	nextNode = nodePtr->next;
      	delete nodePtr;
      	nodePtr = nextNode;
      	count--;
   	}
   	
}
template <class T>
LinkedList<T>::~LinkedList()
{
   	ListNode<T> *nodePtr;
   	ListNode<T> *nextNode;
   	nodePtr = head;

   	while (nodePtr != NULL){
      	nextNode = nodePtr->next;
      	delete nodePtr;
      	nodePtr = nextNode;
   	}
   	count=0;
}
