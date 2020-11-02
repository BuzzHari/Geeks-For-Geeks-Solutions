// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

int getCountOfNode(Node*, int, int);


Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    
    return root;
}

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        cout<<getCountOfNode(root,l,h)<<endl;
    
        
    }
	return 0;
}  // } Driver Code Ends



/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Idea is to visit all the nodes and just check if the node value 
// lies between the range. 
int getCountOfNode(Node *root, int l, int h)
{
    // your code goes here   
    if (!root)
        return 0;

    if (root->data >= l && root->data <= h)
        return 1 + (getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h));
    else 
        return  (getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h));

}

