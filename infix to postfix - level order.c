#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct tree{
	char data;
	struct tree *left;
	struct tree *right;
}*TreeNode;

TreeNode treestack[30];
int treetop=-1;


TreeNode newnode(char b){
	TreeNode temp;
	temp=(struct tree*)malloc(sizeof(struct tree));
	temp->data=b;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
}

void treepush(TreeNode temp){
	treestack[++treetop]=temp;
}

TreeNode treepop(){
	TreeNode p;
	p=treestack[treetop--];
	return(p);
}

TreeNode Build_Binary_Expression_Tree(char* postfix){
	TreeNode temp;
	int i;
	while(*postfix != '\0'){
		if(*postfix=='*' || *postfix=='/' || *postfix=='+' || *postfix=='-'){
			temp=newnode(*postfix);
			temp->right=treepop();
			temp->left=treepop();
			treepush(temp);
			postfix++;
		}
		else{
			temp=newnode(*postfix);
			treepush(temp);
			postfix++;
		}
	}
	return temp;
}


char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

char* infix_to_postfix(char* infix){
	
	char * postfix = (char*)malloc(100 * sizeof(char));
	char x;
	int i = 0;
	while(*infix != '\0')
    {
        if(isalnum(*infix))
            postfix[i++] = *infix; 
        else if(*infix == '(')
            push(*infix);
        else if(*infix == ')')
        {
            while((x = pop()) != '(')
                postfix[i++] = x; 
        }
        else
        {
            while(priority(stack[top]) >= priority(*infix)){
            	postfix[i++] = pop(); 
			} 
            push(*infix);
        }
        infix++;
    }
    
    while(top != -1)
    {
        postfix[i++] = pop(); 
    }
    postfix[i] = '\0';
    return postfix;
    
}
void printCurrentLevel(TreeNode root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void printLevelOrder(TreeNode root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printCurrentLevel(root, i);
}

int height(TreeNode node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
 

int main(){
	
	char exp[100];
    char *infix;
    printf("Enter the expression : ");
    scanf("%s",exp);
    infix = exp;
    char * postfix = infix_to_postfix(infix);
    printf("Postfix version of entered infix string : %s\n", postfix);
	
	TreeNode root = Build_Binary_Expression_Tree(postfix);
	printf("Level order traversal of constructed tree :");
	printLevelOrder(root);
	
	
	
	return 0;
}
