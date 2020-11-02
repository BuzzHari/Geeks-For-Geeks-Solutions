#include <iostream>

using namespace std;

struct Node  {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node *root, int val) {

    if (!root) {
        Node *new_node = new Node(val);
        return new_node;
    }

    if (val >= root->data)
        root->right = insert(root->right, val);
    else if (val < root->data)
        root->left = insert(root->left, val);

    return root;
}

// Preodred traversal. 
void preorder(Node *root) {
    if (!root)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Recursvly insert elements into the BST. 
void insert_wrapper(Node **root, int arr[], int l, int r) {
     
    if (l <= r) {
        int mid = l + (r-l)/2;
        *root = insert(*root, arr[mid]);
        insert_wrapper(root, arr, l, mid-1);
        insert_wrapper(root, arr, mid+1, r);
    }
}

int main() {

    int t;
    cin >> t;
    int n;
    int arr[1001];
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Node *root = NULL;
        insert_wrapper(&root, arr, 0, n-1);

        preorder(root);
        cout << "\n";
    }
}
