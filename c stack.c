#include<stdio.h>
#include<stdlib.h>


struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 

struct stack
{
  struct node *pushnode;
  struct stack *next;
};

void inOrder(struct node *root)
{
	// to print inorder of bst without using recursion we must use stacks...
	
  struct node *currentnode = root; // baslanan node
  struct stack *stackpointer = NULL;  // stack
  int done = 0;
 
  while (!done)
  {
    if(currentnode !=  NULL)
    {

      push(&stackpointer, currentnode);                                               
      currentnode = currentnode->left;  
    }

    else                                                             
    {
      if (!isEmpty(stackpointer))
      {
        currentnode = pop(&stackpointer);
        printf("%d ", currentnode->data);

        currentnode = currentnode->right;
      }
      else
        done = 1; 
    }
  } 
}


void push(struct stack** stackstart, struct node *pushnode)
{
  struct stack* newnode =
            (struct stack*) malloc(sizeof(struct stack));
 
  if(newnode == NULL)
  {
     printf("Stack bos \n");
     getchar();
     exit(0);
  }            
 
  newnode->pushnode  = pushnode;
 
  newnode->next = (*stackstart);   
 
  (*stackstart)    = newnode;
}
     

int main(){
	
	
	return 0;
}









