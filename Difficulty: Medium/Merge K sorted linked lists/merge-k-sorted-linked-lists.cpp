//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           if(K==0) return NULL;
           Node* head=arr[0];
           for(int i=1;i<K;i++)
           {
               head=sortedMerge(head,arr[i]);
           }
           return head;
    }
    Node* sortedMerge(Node* head1, Node* head2)  
{  
   Node* temp1=head1;
   Node* temp2=head2;
   Node* dummy=new Node(-1);
   Node* curr=dummy;
   while(temp1!=NULL && temp2!=NULL)
   {
       if(temp1->data<temp2->data)
       {
           curr->next=temp1;
           curr=temp1;
           temp1=temp1->next;
       }
       else if(temp1->data>=temp2->data)
       {
           curr->next=temp2;
           curr=temp2;
           temp2=temp2->next;
       }
    //   else
    //   {
    //       Node* newnode=new Node(temp1->data);
    //       curr->next=newnode;
    //       curr=newnode;
    //       if(temp1)temp1=temp1->next;
    //       Node* newnode1=new Node(temp2->data);
    //       curr->next=newnode1;
    //       curr=newnode1;
    //       if(temp2)temp2=temp2->next;
    //   }
   }
   while(temp1)
   {
       curr->next=temp1;
       curr=temp1;
       temp1=temp1->next;
   }
   while(temp2)
   {
       curr->next=temp2;
       curr=temp2;
       temp2=temp2->next;
   }
   return dummy->next;
} 
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends