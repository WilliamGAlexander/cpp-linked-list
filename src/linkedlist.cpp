#include <cstdlib>
#include <iostream>

#include "linkedlist.h"

using namespace std;

void Node::deleteNextAndSelf() {
    if (this -> next) {
        this -> next -> deleteNextAndSelf();
    }

    delete this;
}

LinkedList::LinkedList(){
    this -> length = 0;
    this -> head = NULL;
}

LinkedList::~LinkedList(){
    head -> deleteNextAndSelf();
}

void LinkedList::add(int val){
    Node *node = new Node();
    //Same as node -> val
    (*node).val = val;
    //Same as node -> next
    (*node).next = this -> head;
    this -> head = node;
    this -> length++;
}

void LinkedList::print(){
    Node* head = this -> head;
    int i = 1;
    while(head){
        cout << i << ": " << head -> val << endl;
        head = head -> next;
        i++;
    }
    
}



int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
    
    for(int i = 0; i < 100; i++){
        list -> add(rand()%100);
    }
    
    list -> print();
    cout << "List length: " << list -> length << std::endl;
    

    delete list; 
   
    return 0;
}



