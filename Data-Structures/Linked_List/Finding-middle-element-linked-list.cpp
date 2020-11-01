// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		cout<<getMiddle(head)<<endl;
	}
	return 0; 
} 

// } Driver Code Ends


/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

// Idea is to use fast and slow pointer. By the time the fastptr 
// reaches the end, the slowptr will at mid, because fastptr moves twice the speed 
// of slowptr.


/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
    if (!head)
        return -1;
    
    Node *slow_ptr = head, *fast_ptr = head;
    int count = 0;
    while(fast_ptr->next) {
        fast_ptr = fast_ptr->next;
        if (fast_ptr->next) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
            count+=2;
        }
        else 
            count+=1;
        
    }
    
   if ( (count+1) % 2)
       return slow_ptr->data;
    else 
       return slow_ptr->next->data;
}

