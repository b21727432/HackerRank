#include<iostream>

using namespace std;

struct QNode { 
    int data; 
    QNode* next; 
    QNode(int d) 
    { 
        data = d; 
        next = NULL; 
    } 
}; 
struct Queue { 
    QNode *front, *rear; 
    Queue() 
    { 
        front = rear = NULL; 
    } 
  
    void enQueue(int x) 
    { 
  
        QNode* temp = new QNode(x); 

        if (rear == NULL) { 
            front = rear = temp; 
            return; 
        } 

        rear->next = temp; 
        rear = temp; 
    } 

    void deQueue() 
    { 
        if (front == NULL) 
            return; 
  

        QNode* temp = front; 
        
        front = front->next; 

        if (front == NULL) 
            rear = NULL; 
  
        delete (temp); 
    } 
    
    int firstn(int n){
    	QNode* temp = front; 
    	
    	int sum = 0;
    	int i = 0;
    	while(temp != NULL){
    		
    		sum += temp->data;
    		i++;
    		temp = temp->next;
    		if(i == n){
    			break;
			}
		}
		return sum;
	}
	
	void deleten(int n){
		QNode* temp = front;
		int i;
		for(i = 0; i < n; i++){
			temp = temp->next;
		} 
		while(temp != NULL){
			QNode* temp2 = temp;
			temp = temp->next;
			temp2 = NULL;
		}
	}
}; 



int main(){
	
	Queue q; 
    q.enQueue(10); 
    q.enQueue(20);
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.enQueue(60); 
	q.enQueue(70); 
	 
	int x = q.firstn(5);
	q.deleten(5);
	
	
	
	return 0;
}
