#include<iostream>

using namespace std;

class BST  
{ 
    char data; 
    BST *left, *right; 
  
public: 
    BST(); 
  
    BST(char); 
  
    BST* Insert(BST*, char); 
  
    void Inorder(BST*); 
}; 
  
BST ::BST() 
    : data(0) 
    , left(NULL) 
    , right(NULL) 
{ 
} 
  
BST ::BST(char value) 
{ 
    data = value; 
    left = right = NULL; 
} 
  
BST* BST ::Insert(BST* root, char value) 
{ 
    if (!root)  
    { 
        return new BST(value); 
    } 
  
    if (value > root->data)  
    { 

        root->right = Insert(root->right, value); 
    } 
    else 
    { 

        root->left = Insert(root->left, value); 
    } 
  
    return root; 
} 
  

void BST ::Postorder(BST* root) 
{ 
    if (!root) { 
        return; 
    } 
    Inorder(root->left); 
    
    Inorder(root->right); 
    
    cout << root->data << endl; 
} 


int main(){
	
	BST b, *root = NULL; 
    root = b.Insert(root, 'y');
	root = b.Insert(root, 'u'); 
	root = b.Insert(root, 's'); 
	root = b.Insert(root, 'u'); 
	root = b.Insert(root, 'f'); 
	root = b.Insert(root, 'k'); 
	root = b.Insert(root, 'u'); 
	root = b.Insert(root, 'r'); 
	root = b.Insert(root, 't'); 
	root = b.Insert(root, 'u'); 
	
	b.Postorder(root); 
	
	 
	
	return 0;
	
}
