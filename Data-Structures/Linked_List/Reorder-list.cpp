// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node* reverse(Node *head) {
    if (!head)
        return NULL;
    
    Node *prev = NULL, *curr = head, *next = head;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void reorderList(Node* head) {
    // Your code here
    if (!head)
        return;
        
    Node *slowptr = head, *fastptr = head;
    while(fastptr->next) {
        fastptr=fastptr->next;
        if (fastptr->next) {
            fastptr=fastptr->next;
            slowptr=slowptr->next;
        }
    }
    Node *first_half = head;
    Node *sec_half = slowptr->next;
    
    slowptr->next = NULL;
    sec_half = reverse(sec_half);
    
    Node *temp1, *temp2;
    while(first_half && sec_half) {
        temp1 = first_half->next;
        temp2 = sec_half->next;
        
        first_half->next = sec_half;
        sec_half->next = temp1;

        sec_half = temp2;
        first_half = temp1;
    }
}





