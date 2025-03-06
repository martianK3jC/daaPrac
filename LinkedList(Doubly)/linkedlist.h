#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

//LinkedList class -> extends to class List
class LinkedList : public List{
	//initialize head and tail, then declare totalSize
	node* head;
	node* tail;
	int totalSize;
	//constructor
	public: 
	
	LinkedList(){
		head = nullptr;
		tail = nullptr;
		totalSize = 0;
	}
	
	//create new node
	node* createNode(int elem){
		node* newNode = new node();
		newNode->elem = elem;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		return newNode;
	}
	
	//insert at the end
	void insert(int elem){
		node* newNode = createNode(elem);
		if(!head){
			head = tail = newNode;	
		}else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		totalSize++;
	}
	
	//get the element at position pos
	int get(int pos){
		if(pos < 1 || pos > totalSize){
			throw logic_error("Invalid position");
		}
		
		node* curr = head;
		for(int i = 1; i < pos; i++){
			curr = curr->next;
		}
		return curr->elem;
	}
	
	//remove first occurence of a number
	int remove(int num){
		node* curr = head;
		int pos = 1;
		
		while(curr){
			if(curr->elem == num){
				if(totalSize == 1){
					head = tail = nullptr;
				}else if(curr == head){
					head = head->next;
					head->prev = nullptr;
				}else if(curr == tail){
					tail = tail->prev;
					tail->next = nullptr;
				}else{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
				}
				delete curr;
				totalSize--;
				return pos;
			}
			curr = curr->next
			pos++;
		}
		return 0;
	}
	
	
	//print the list
	void print(){
		cout<<"FROM HEAD: ";
		if(totalSize == 0){
			cout<<"(none)"<<endl;
		}else{
			node* curr = head;
			while(curr){
				cout<<curr->elem;
				if(curr->next){
					cout<<" -> ";
				}
				curr = curr->next;
			}
			cout<<endl;
		}
		
		cout<<"FROM TAIL: ";
		if(totalSize == 0){
			cout<<"(none)"<<endl;
		}else{
			node* curr = tail;
			while(curr){
				cout<<curr->elem;
				if(curr->prev){
					cout<< " <- ";
				}
				curr = curr->prev;
			}
			cout<<endl;
		}
	}
	
	//get the size of the list
	int size(){
		return totalSize;
	}
	
	//check of the list is empty
	bool isEmpty(){
		return size() == 0;
	}
	
	//insert at a specific position
	void addAt(int num, int pos){
		if(pos < 1 || pos > totalSize + 1){
			throw logic_error("Invalid Position");
		}
		
		node* newNode = createNode(num);
		
		if(pos == 1){
			newNode->next = head;
			//if head is not empty
			if(head){
				head->prev = newNode;	
			}
			head = newNode;
			
			//if tail is empty
			if(!tail){
				tail = newNode;
			}
		}else if(pos == totalSize + 1){//if pos is at last position
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}else{
			node* curr = head;
			for(int i = 1; i < pos - 1; i++){
				curr = curr->next;
			}
			newNode->next = curr->next;
			newNode->prev = curr;
			curr->next->prev = newNode;
			curr->next = newNode;
		}
		totalSize++;
	}
	
	//remove at a specific position
	int removeAt(int pos){
		if(pos < 1 || pos > totalSize){
			throw logic_error("Invalid position");
		}
		
		node* curr = head;
		for(int i = 1; i < pos; i++){
			curr = curr->next;
		}
		
		int returner = curr->elem;
		
		if(totalSize == 1){
			head = tail = nullptr;
		}else if(curr == head){
			head = head->next;
			head->prev = nullptr;
		}else if(curr == tail){
			tail = tail->prev;
			tail->next = nullptr;
		}else{
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
		}
		
		delete curr;
		totalSize--;
		return returner;
	}
};