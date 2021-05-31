
class Node
{
	public:
		int data;
    	Node *left, *right;
 
    	Node(int data)
    	{
        	this->data = data;
        	this->left = this->right = nullptr;
    	}
};

bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}

void printLeafToRootPaths(Node* node)
{
    vector<int> path;
 
    printLeafToRootPaths(node, path);
}

void printLeafToRootPaths(Node* node, vector<int> &path)
{
    if (node == nullptr) {
        return;
    }
 
    path.push_back(node->data);
 
    if (isLeaf(node)) {
        printPath(path);
    }
 
    printLeafToRootPaths(node->left, path);
    printLeafToRootPaths(node->right, path);
 
    path.pop_back();
}

void printPath(vector<int> const &path)
{
	int toplam = 0;
    for (int i = path.size() - 1; i > 0; i--) {
        cout << path.at(i) << " + ";
        toplam += path.at(i);
    }
 	toplam += path.at(0);
    cout << path.at(0) << " = " << toplam << endl;
    
}

int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printLeafToRootPaths(root);
 
    return 0;
}
