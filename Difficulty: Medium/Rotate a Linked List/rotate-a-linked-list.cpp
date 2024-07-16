//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head==NULL || head->next==NULL) return head;
       Node* temp=head;
       int n=0;
       Node* last=NULL;
       while(temp)
       {
           n++;
           if(temp->next==NULL)
           last=temp;
           temp=temp->next;
           
       }
       k=k%n;
       if(k==0) return head;
       int cnt=1;
       Node* knode=NULL;
       temp=head;
       while(temp)
       {
           if(cnt==k)
           knode=temp;
           cnt++;
           temp=temp->next;
       }
       Node* newhead=knode->next;
       knode->next=NULL;
       last->next=head;
       return newhead;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends