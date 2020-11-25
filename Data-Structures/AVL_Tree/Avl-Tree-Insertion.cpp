// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

int getHeight(Node *node) {
    if (!node)
        return -1;
    return node->height;
}

void updateHeight(Node *node) {
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

Node* singleRotationLL(Node* node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    
    updateHeight(node);
    return temp;
}

Node* singleRotationRR(Node* node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    
    updateHeight(node);
    return temp;
}

Node* doubleRotationLR(Node* node) {
    node->left = singleRotationRR(node->left);
    return singleRotationLL(node);
}

Node* doubleRotationRL(Node* node) {
    node->right = singleRotationLL(node->right);
    return singleRotationRR(node->left);
}

/*You are required to complete this method */
Node* insertToAVL(Node* node, int data)
{
    //Your code here
    if (!node) {
        node = new Node(data);
    }  
    
    // Insert into left. 
    else if (data < node->data) {
        node->left = insertToAVL(node->left, data);
        
        // Check left subtree and right subtee balance. 
        if (abs(getHeight(node->left) - getHeight(node->right)) > 1) {
            // Check if LL case.
            if (data < node->left->data)
                node = singleRotationLL(node);
            else 
            // LR case. 
                node = doubleRotationLR(node);
        }
    }
    // Insert into right
    else if (data > node->data) {
        node->right = insertToAVL(node->right, data);
        
        // Check left subtree and right subtree balance. 
        if (abs(getHeight(node->left) - getHeight(node->right)) > 1) {
            // Check if RR case.
            if (data > node->right->data)
                node = singleRotationRR(node);
            else 
                node = doubleRotationRL(node);
        }
    }
    else { 
        // Duplicate insertion, do nothing. 
    }
    //update hight of node.
    updateHeight(node);
    return node;
}
