//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
     Node* fast=head;
     Node* slow=head;
     if(head==NULL || head->next==NULL) return head;
     while(fast->next!=NULL && fast->next->next!=NULL)
     {
        fast=fast->next->next;
        slow=slow->next;
     }
     Node* newhead=reverse(slow->next);
     Node* first=head;
     Node* second=newhead;
     Node* temp=first;
     while(temp!=slow->next)
     {
        temp=temp->next;
     }
     Node* t=second;
     while(t)
     {
        t=t->next;
     }
     while(second)
     {
        if(first->data!=second->data)
        {
            reverse(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
     }
     reverse(newhead);
     return true;
    }
    Node* reverse(Node* head)
    {
        Node* temp=head;
        Node* prev=NULL;
        while(temp)
        {
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends