#include <iostream>
using namespace std;
//Queue.h
template <class T>
class queueNode{
	public:
 		T value; // Node value
 		queueNode<T> *next; // Pointer to the next node
 		// Constructor
 		queueNode (T nodeValue){ 
		 	value = nodeValue;
 			next = NULL;}
};
template <class T>
class queue {
	private:
 		queueNode<T> *qFront;
 		queueNode<T> *qRear;
 		int count;
	public:
 		void enQueue(T);
 		void deQueue();
 		T front(); //to return front value of a Queue
 		bool IsEmptyQueue();
 		void destroyQueue();
 		void numQueueNode(){
 			return count;}
 		void CopyReverse(queue<char>);
 		void Copy(queue<char>);
 		queue();
 		~queue();
};
template <class T>
void queue <T>::enQueue(T newValue){
	queueNode<T> *newNode;
	newNode = new queueNode<T>(newValue);
	if (qFront==NULL){
		qFront=newNode;
		qRear=newNode;
 	}
 	else {
 		qRear->next=newNode;
 		qRear=newNode;
 	}
	count++;
}
template <class T>
void queue <T>::deQueue(){
	queueNode<T> *nodePtr;
	if (qFront==NULL)
		cout << "Queue is Empty...\n"; 
 	else {
 		nodePtr=qFront;
 		qFront=qFront->next; //eqv to nodePtr->next
 		delete nodePtr;
 		count--;
 	}
}
template <class T>
T queue <T>::front() {
 	return qFront->value;
}
template <class T>
	bool queue<T>::IsEmptyQueue() {
	if (qFront==NULL)
 		return true;
	else
 		return false;
}
template <class T>
void queue <T>::destroyQueue(){
 	queueNode<T> *nodePtr;
 	while (!IsEmptyQueue()){ //while (qFront!=Null)
 		nodePtr=qFront;
 		qFront=qFront->next;
 		delete nodePtr;
	}
	count=0;
}

template <class T>
void queue <T>::CopyReverse(queue<char> Queue){
	queue<char> tempQueue;
	tempQueue.enQueue(Queue.front());
	Queue.deQueue();
	enQueue(Queue.front());
	Queue.deQueue();
	enQueue(tempQueue.front());
	tempQueue.deQueue();
	while(!Queue.IsEmptyQueue()){
		tempQueue.enQueue(Queue.front());
		Queue.deQueue();
		while(!IsEmptyQueue()){
			tempQueue.enQueue(front());
			deQueue();
		}
		while(!tempQueue.IsEmptyQueue()){
			enQueue(tempQueue.front());
			tempQueue.deQueue();
		}
		count++;
	}
}
template <class T>
void queue <T>::Copy(queue<char> Queue){
	while(!Queue.IsEmptyQueue()){
		enQueue(Queue.front());
		Queue.deQueue();
		count++;
	}
}
template <class T>
queue <T>::queue(){
	qFront=NULL;
	qRear=NULL;
	count=0;
}
template <class T>
queue <T>::~queue(){
	destroyQueue();
}
