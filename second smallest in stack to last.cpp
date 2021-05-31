#include <stack>
#include <iostream>

struct Node
{
    public:
    int data;
    Node *next;
};

using namespace std;

int main() {
	stack<int> stack;
	stack.push(5);
	stack.push(7);
	stack.push(8);
	stack.push(11);
	stack.push(14);
	stack.push(17);
	stack.push(101);
	
	while (!stack.empty()){
      insertNode(stack.top());
      stack.pop();
   }
	
	int first = INT_MAX, second = INT_MAX;
  
    struct Node* temp = head;
    while (temp != NULL) {
  
        if (temp->data < first) {
            second = first;
            first = temp->data;
        }
  
        else if (temp->data < second && temp->data != first)
            second = temp->data;
  
        temp = temp->next;
    }
    
    int degerler[7] = {5,7,8,11,14,17,101};
    for(int i = 0; i < 7; i++){
    	if(degerler[i] != second){
    		stack.push(i);
		}
	}
	stack.push(second);
    
    
}
