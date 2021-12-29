#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "Linklist.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int readfile(LinkedList<string>[],int[]);
void StoreintoChar(LinkedList<string>[],stack<char>[],queue<char>[],int);
void Anagram(LinkedList<string>[],int,int[]);
void copyStack(stack<char>,stack<char>&,int);
void copyQueue(queue<char>,queue<char>&,int);
int main(){
	int size=1000;
	LinkedList<string> List[size];
	stack<char> Stack[size],Stack1[size];
	queue<char> Queue[size],Queue1[size];
	int StackQueueSize[size];
	int C,c=0,var;
	string word,word2;
	
	cout<<"\n\tWelcome to Anagram Generator !!"<<"\n\n\t";
	system("pause");
	system("cls");
	cout<<"\n\n\t\tRead File . . . . .\n\t";
	size=readfile(List,StackQueueSize);
	system("pause");
	
	cout<<"\tWords inside file : "<<"\n\n";
	for(int i=0;i<size;i++){
		cout<<"\t\t->"<<List[i].firstNode();
		cout<<endl;
	}
	StoreintoChar(List,Stack,Queue,size);
	system("pause");
	system("cls");
	
	do{	//display menu
		cout<<"\n\n\t---------------------------------------------------------------------------------\n\t\t\t\tAnagram Generator";
		cout<<"\n\t---------------------------------------------------------------------------------\t";	
		cout<<"\n\n\t\tChoose the following option :\n\n\t\t[1]-List of Words."<<"\n\t\t[2]-All Anagram Permutation.";
		cout<<"\n\t\t[3]-Anagram with Starting Letter. "<<"\n\t\t[4]-Add Word/Words.";
		cout<<"\n\t\t[5]-Update Word and it Anagram."<<"\n\t\t[6]-Delete word and it Anagram.";
		cout<<"\n\t\t[7]-Exit."<<"\n\n\t\tOption : ";	
		cin>>C;system("CLS");
		//task that provide by the program 
		switch(C){
			case 1:	cout<<"\n\tList of Words : "<<"\n\n";
					for(int i=0;i<size;i++){
						cout<<"\t\t->"<<List[i].firstNode();
						cout<<endl;
					}
					system("pause");
					system("CLS");
					break;
			case 2: Anagram(List,size,StackQueueSize);
					cout<<"\n\tList of Words with it Anagram :"<<endl<<endl;
					for(int i=0;i<size;i++){
						cout<<"\n\t\tWord "<<i+1<<" -"<<List[i].firstNode();
						List[i].displayList();
					}
					system("pause");
					system("CLS");
					break;
			case 3: do{
						cout<<"\n\tEnter Word that you want to search : ";
						cin>>word;
						bool found=false;
						int i=0;
						while(i<size){
							if(word==List[i].firstNode()){
								found=true;break;}
							i++;
						}
						if(!found)
							cout<<"\n   There is no '"<<word<<"' word in this program !"<<endl<<endl;
						else{
							cout<<"\n\tEnter Starting letter for Anagram : ";
							char a;
							cin>>a;
							cout<<"\n\tAnagram : "<<endl;
							List[i].search(a);
							break;
						}
						system("pause");
						system("CLS");
						cout<<"\n   Do you want to keep searching ? [1-yes,2-no]\n\tChoice :";
						cin>>c;
						if(c==2){
							system("pause");system("cls");
							break;}
						else if(c==1){
							system("pause");system("cls");}
						else{
							while(c!=1||c!=2){
								cout<<"\tEnter Again : ";
								cin>>c;
							}
						}	
					}while(c==1);
					system("pause");
					system("CLS");
					break;
			case 4: cout<<"\n   How many word you want to enter ? \n   ";
					cin>>var;
					int i;
					for(i=0;i<var;i++){
						cout<<"\n\tWord "<<i+1<<" : ";
						cin>>word;
						List[i+size].appendNode(word);
						StackQueueSize[i+size]=word.length();
					}
					size=size+i;
					Anagram(List,size,StackQueueSize);
					system("pause");
					system("CLS");
					break;
			case 5: do{
						cout<<"\n\tEnter Word that you want to Update : ";
						cin>>word;
						bool found=false;
						int i=0;
						while(i<size){
							if(word==List[i].firstNode()){
								found=true;
								List[i].destroyList();
								break;
							}
							i++;
						}
						if(!found)
							cout<<"\n   There is no '"<<word<<"' word in this program !"<<endl<<endl;
						else{
							cout<<"\n\tEnter new updated word : ";
							cin>>word2;
							for(int j=0;j<StackQueueSize[i];j++){
								Stack[i].Pop();
								Queue[i].deQueue();
							}
							for(int j=0;j<word.length();j++){
								Stack[i].Push(word[j]);
								Queue[i].enQueue(word[j]);
							}
							List[i].appendNode(word);
							Anagram(List,size,StackQueueSize);
							cout<<"\n\t\tWord "<<i+1<<" -"<<List[i].firstNode();
							List[i].displayList();
						}
						system("pause");
						system("CLS");
						cout<<"\n   Do you want to keep Updating ? [1-yes,2-no]\n\tChoice :";
						cin>>c;
						if(c==2){
							system("pause");system("cls");
							break;}
						else if(c==1){
							system("pause");system("cls");}
						else{
							while(c!=1||c!=2){
								cout<<"\tEnter Again : ";
								cin>>c;
							}
						}	
					}while(c==1);
					system("pause");
					system("CLS");
					break;
			case 6: do{
						cout<<"\n\tEnter Word that you want to delete word and its anagram : ";
						cin>>word;
						bool found=false;
						int i=0;
						while(i<size){
							if(List[i].firstNode()==word){
								found=true;
								break;
							}i++;
						}
						if(!found)
							cout<<"\n   There is no '"<<word<<"' word in this program !"<<endl<<endl;
						else{
							for(int j=0;j<StackQueueSize[i];j++){
								List[i].deleteNode(List[i].firstNode());
							}
							while(i<size){
								List[i].CopyList(List[i+1]);
								List[i+1].destroyList();
								StackQueueSize[i]=StackQueueSize[i+1];
								i++;
							}
						}
						size--;
						system("pause");
						system("CLS");
						cout<<"\n   Do you want to keep Deleting ? [1-yes,2-no]\n\tChoice :";
						cin>>c;
						if(c==2){
							system("pause");system("cls");
							break;}
						else if(c==1){
							system("pause");system("cls");}
						else{
							while(c!=1||c!=2){
								cout<<"\tEnter Again : ";
								cin>>c;
							}
						}	
					}while(c==1);
					system("pause");
					system("CLS");
					break;
			case 7: 
					
					system("pause");
					system("CLS");
					break;
			default:cout<<"\tChoice is not valid...\nEnter again\n";
		}
	}while(C!=9);
	
	
	
	
	
}
int readfile(LinkedList<string> List[],int StackQueueSize[]){
	ifstream readData;
	string name[1000];
	int i=0;
	
	readData.open("name.txt");
	while(!readData.eof()){
		if(readData.eof()==true)
			break;
		else{
			readData>>name[i];
			List[i].appendNode(name[i]);
			StackQueueSize[i]=name[i].length();
			i++;
		}
	}
	readData.close();
	return i;
}
void StoreintoChar(LinkedList<string> List[],stack<char> Stack[],queue<char> Queue[],int size){
	string name[size];
	int StackQueueSize[size];
	stack<char> Stack1[size];
	queue<char> Queue1[size];
	for(int i=0;i<size;i++){
		name[i]=List[i].firstNode();
		StackQueueSize[i]=name[i].length();
	}
	for(int a=0;a<size;a++){
		char charname[name[a].length()];
		for(int b=0;b<StackQueueSize[a];b++)
			charname[b]=name[a][b];
		for(int b=0;b<StackQueueSize[a];b++){
			Stack[a].Push(charname[b]);
			Queue[a].enQueue(charname[b]);
		}	
	}
	cout<<"Stack : \t\tQueue :"<<endl<<endl;
	for(int i=0;i<size;i++){
		Stack1[i].CopyStack(Stack[i]);
		for(int j=0;j<StackQueueSize[i];j++){
			cout<<Stack[i].Top();
			Stack[i].Pop();
		}
		Stack[i].CopyStack(Stack1[i]);
		cout<<"\t\t\t";
		Queue1[i].Copy(Queue[i]);
		for(int j=0;j<StackQueueSize[i];j++){
			cout<<Queue[i].front();
			Queue[i].deQueue();
		}
		Queue[i].Copy(Queue1[i]);
		cout<<endl;
	}
}
void copyStack(stack<char> Stack,stack<char> &tempStack,int StackQueueSize){
	queue<char> tempQueue;
		for(int j=0;j<StackQueueSize;j++){
			tempQueue.enQueue(Stack.Top());
			Stack.Pop();
		}
		for(int j=0;j<StackQueueSize;j++){
			tempStack.Push(tempQueue.front());
			tempQueue.deQueue();
		}
}
void copyQueue(queue<char> Queue,queue<char> &tempQueue,int StackQueueSize){
		for(int j=0;j<StackQueueSize;j++){
			tempQueue.enQueue(Queue.front());
			Queue.deQueue();
		}
}
void Anagram(LinkedList<string> List[],int size,int StackQueueSize[]){
	stack<char> Stack[size],tempStack[size],tempStack2[size],tempStack3[size];
	queue<char> Queue[size],tempQueue[size];
	StoreintoChar(List,Stack,Queue,size);
	string word1, word2,word3,word4;
	for(int i=0;i<size;i++){
		for(int j=0;j<StackQueueSize[i];j++)
			Queue[i].deQueue();
	}
	for(int i=0;i<size;i++){
		if(List[i].CountNodes()==1){
			tempStack[i].CopyStack(Stack[i]);
			if(StackQueueSize[i]==2){
				word2="";
				for(int j=0;j<StackQueueSize[i];j++){
					word2=word2+Stack[i].Top();
					Stack[i].Pop();
				}
				List[i].appendNode(word2);
				Stack[i].CopyStack(tempStack[i]);
				Stack[i].SwapStack(0,1);
				word2="";
				for(int j=0;j<StackQueueSize[i];j++){
					word2=word2+Stack[i].Top();
					Stack[i].Pop();
				}
				List[i].appendNode(word2);
				Stack[i].CopyStack(tempStack[i]);
			}
			else if(StackQueueSize[i]==3){
				for(int j=0;j<StackQueueSize[i];j++){
					word1="";
					word2="";
					Stack[i].moveTopToBottom();
					tempStack2[i].CopyStack(Stack[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						word1=word1+Stack[i].Top();
						Stack[i].Pop();
					}
					
					Stack[i].CopyStack(tempStack2[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						tempQueue[i].enQueue(tempStack2[i].Top());
						tempStack2[i].Pop();
					}
					Queue[i].CopyReverse(tempQueue[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						word2=word2+Queue[i].front();
						Queue[i].deQueue();
						tempQueue[i].deQueue();
					}
					if(List[i].Found(word1)){
						if(word1==List[i].firstNode())
							List[i].appendNode(word1);}
					else
						List[i].appendNode(word1);
					if(List[i].Found(word2)){
						if(word2==List[i].firstNode())	
							List[i].appendNode(word2);}
					else
						List[i].appendNode(word2);
				}
				for(int k=0;k<StackQueueSize[i];k++)
					Stack[i].Pop();
				Stack[i].CopyStack(tempStack[i]);
			}
			else {
				for(int j=0;j<StackQueueSize[i];j++){
					word1="";
					word2="";
					Stack[i].moveTopToBottom();
					tempStack2[i].CopyStack(Stack[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						word1=word1+Stack[i].Top();
						Stack[i].Pop();
					}
					Stack[i].CopyStack(tempStack2[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						tempQueue[i].enQueue(tempStack2[i].Top());
						tempStack2[i].Pop();
					}
					Queue[i].CopyReverse(tempQueue[i]);
					for(int k=0;k<StackQueueSize[i];k++){
						word2=word2+Queue[i].front();
						Queue[i].deQueue();
						tempQueue[i].deQueue();
					}
					if(List[i].Found(word1)){
						if(word1==List[i].firstNode())
							List[i].appendNode(word1);
						else
							cout<<"Same word with a word in link list! "<<endl;}
					else
						List[i].appendNode(word1);
					if(List[i].Found(word2)){
						if(word2==List[i].firstNode())	
							List[i].appendNode(word2);
						else
							cout<<"Same word with a word in link list! "<<endl;}
					else
						List[i].appendNode(word2);
				}
				for(int k=0;k<StackQueueSize[i];k++)
					Stack[i].Pop();
				Stack[i].CopyStack(tempStack[i]);
				for(int j=0;j<StackQueueSize[i];j++){
					Stack[i].moveTopToBottom();
					tempStack2[i].CopyStack(Stack[i]);
					for(int k=0;k<(StackQueueSize[i]-1);k++){
						Stack[i].SwapStack(k,k+1);
						tempStack3[i].CopyStack(Stack[i]);
						word3="";
						word4="";
						for(int m=0;m<StackQueueSize[i];m++){
							word3=word3+Stack[i].Top();
							Stack[i].Pop();
						}
						for(int m=0;m<StackQueueSize[i];m++){
							tempQueue[i].enQueue(tempStack3[i].Top());
							tempStack3[i].Pop();
						}
						Queue[i].CopyReverse(tempQueue[i]);
						for(int m=0;m<StackQueueSize[i];m++){
							word4=word4+Queue[i].front();
							Queue[i].deQueue();
							tempQueue[i].deQueue();
						}
						if(List[i].Found(word3)==false)
							List[i].appendNode(word3);
						if(List[i].Found(word4)==false)
							List[i].appendNode(word4);
						Stack[i].CopyStack(tempStack2[i]);
					}
					for(int k=0;k<StackQueueSize[i];k++)
						tempStack2[i].Pop();
				}
				for(int k=0;k<StackQueueSize[i];k++)
					Stack[i].Pop();
				Stack[i].CopyStack(tempStack[i]);
				int a=StackQueueSize[i]-1;
				while(a!=1){
					word1="";
					word2="";
					if(a==StackQueueSize[i]-1){
						int count=1;
						Stack[i].SwapStack(count,a);
						tempStack2[i].CopyStack(Stack[i]);
						for(int k=0;k<StackQueueSize[i];k++){
							word1=word1+Stack[i].Top();
							Stack[i].Pop();
						}
						Stack[i].CopyStack(tempStack[i]);
						for(int k=0;k<StackQueueSize[i];k++){
							tempQueue[i].enQueue(tempStack2[i].Top());
							tempStack2[i].Pop();
						}
						Queue[i].CopyReverse(tempQueue[i]);
						for(int k=0;k<StackQueueSize[i];k++){
							word2=word2+Queue[i].front();
							Queue[i].deQueue();
							tempQueue[i].deQueue();
						}
						if(List[i].Found(word1)==false)
							List[i].appendNode(word1);
						if(List[i].Found(word2)==false)
							List[i].appendNode(word2);
					}
					else{
						int count=0;
						while(count<a-1){
							word3="";
							word4="";
							Stack[i].SwapStack(count,a);
							tempStack2[i].CopyStack(Stack[i]);
							for(int k=0;k<StackQueueSize[i];k++){
								word1=word1+Stack[i].Top();
								Stack[i].Pop();
							}
							Stack[i].CopyStack(tempStack[i]);
							for(int k=0;k<StackQueueSize[i];k++){
								tempQueue[i].enQueue(tempStack2[i].Top());
								tempStack2[i].Pop();
							}
							Queue[i].CopyReverse(tempQueue[i]);
							for(int k=0;k<StackQueueSize[i];k++){
								word2=word2+Queue[i].front();
								Queue[i].deQueue();
								tempQueue[i].deQueue();
							}
							if(List[i].Found(word3)==false)
								List[i].appendNode(word3);
							if(List[i].Found(word4)==false)
								List[i].appendNode(word4);
							count++;
						}
					}
					a--;
				}
			}
		}
	}
}
