// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

  // TO BE REMOVED
  for (int i=0; i<2000; i++);


    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    if (!head)
        return NULL;
    
    Node *ptr = head;
    Node *prev = NULL;
    Node *temp = NULL;
    int flag = 0;
    while(ptr) {
        if (ptr->data == x && ptr == head) {
            temp = ptr;
            head = head->next;
        }
        else if (ptr->data == x) {
            temp = ptr;
            prev->next = ptr->next;
            flag = 1;
        }
        
        // Don't uptate the prev if a deletion has occured.
        if (!flag)
            prev = ptr;
        flag = 0;
        ptr = ptr->next;
        if (temp)
            free(temp);
        temp = NULL;
    }
    
    return head;

}

