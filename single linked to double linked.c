#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node { 
    int data; 
    struct Node* next; 
}; 

struct DNode { 
    int data; 
    struct Node* next; 
    struct Node* prev;
}; 



void DNode* singletodouble(Struct Node* n){
	
	Struct DNode* dnode = NULL;
	dnode->data = n->data; 
	while(n != NULL){
		dnode->prev = NULL;
		dnode->prev->data = n->next->data;
		dnode = dnode->prev;
		n = n->next;
	}
	
	Struct DNode* temp = NULL;
	while(dnode != NULL){
		dnode->prev = temp;
		temp->next = dnode;
		dnode = dnode->prev;
	}
	
	return dnode;
}


int main(){
	
	
	
	
	return 0;
}
