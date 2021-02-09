struct node { 
    int data; 
    struct node *left, *right; 
}; 


struct node* print_path(struct node* root, int data) 
{ 
    if (node == NULL){
    	printf("path is found");	
	}
		
  
    if (key < node->data){
    	printf("to the left of %d", root->data); 
        root->left = insert(root->left, data); 
	}
		
    else if (data > node->data){
    	printf("to the right of %d", root->data); 
        root->right = insert(root->right, data); 
	}
		
  
    return root; 
} 
