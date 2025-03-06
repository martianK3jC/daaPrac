#include "node.hpp"
#include <iostream>
using namespace std;
class LinkedList {
    node* head;
    node* tail;
	int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
 
 	node* createNode(int elem){
 		node* newNode = new node();
 		newNode->elem = elem;
 		newNode->next = nullptr;
 		return newNode;
	 }
	 
    void add(int elem) {
        node* new_node = createNode(elem);
        if (isEmpty()) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = tail->next;
        }
        ++size;
    }
    
    void remove(int elem) {
	    if (!exists(elem)) return;
	
	    node* to_delete = nullptr;
	
	    if (head->elem == elem) {  
	        to_delete = head;  
	        head = head->next;
	        if (head == nullptr) tail = nullptr;  // If list becomes empty
	    } else {
	        node* curr = head;
	        while (curr->next != nullptr && curr->next->elem != elem) {
	            curr = curr->next;
	        }
	
	        if (curr->next == nullptr) return; // Element not found
	        to_delete = curr->next;
	        curr->next = curr->next->next;
	        if (curr->next == nullptr) tail = curr;  // Update tail if needed
	    }
	
	    delete to_delete;
	    --size;
	}
    
    bool exists(int elem) {
        if (isEmpty()) return false;
        
        node* current = head;
        while (current != nullptr && current->elem != elem) {
            current = current->next;
        }
        return current != nullptr;
    }
    
    void print() {
        if (isEmpty()) return;
        node* curr = head;
        while (curr != nullptr) {
            cout << curr->elem << '\t';
            curr = curr->next;
        }
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
};
    