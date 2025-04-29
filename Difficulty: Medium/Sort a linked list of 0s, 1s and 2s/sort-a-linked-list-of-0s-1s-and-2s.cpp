//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head==NULL || head->next==NULL) return head;
        Node* zero=new Node(-1);
        Node* one=new Node(-1);
        Node* two=new Node(-1);
        Node* cur1=zero;
        Node* cur2=one;
        Node* cur3=two;
        Node* temp=head;
        while(temp)
        {
            if(temp->data==0)
            {
                Node* newnode1=new Node(0);
                cur1->next=newnode1;
                cur1=newnode1;
            }
            else if(temp->data==1)
            {
                Node* newnode2=new Node(1);
                cur2->next=newnode2;
                cur2=newnode2;
            }
            else 
            {
                Node* newnode3=new Node(2);
                cur3->next=newnode3;
                cur3=newnode3;
            }
            temp=temp->next;
        }
        cur1->next=(one->next)?one->next:two->next;
        cur2->next=two->next;
        cur3->next=NULL;
        return zero->next;
        
    }
};





//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends