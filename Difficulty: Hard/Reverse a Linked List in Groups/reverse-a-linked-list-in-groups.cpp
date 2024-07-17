//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        node* temp=head;
        node* prev=NULL;
        while(temp)
        {
            node* knode=getknode(temp,k);
            if(knode==NULL)
            {
                node* back=reverse(temp);
                prev->next=back;
                break;
            }
            node* nextnode=knode->next;
            knode->next=NULL;
            reverse(temp);
            if(temp==head)
            {
                head=knode;
            }
            else
            prev->next=knode;
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
    node* getknode(node* temp,int k)
    {
        k-=1;
        while(temp!=NULL && k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    node* reverse(node* temp)
    {
        node* prev=NULL;
        while(temp!=NULL)
        {
            node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends