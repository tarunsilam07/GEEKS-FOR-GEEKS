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

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
       Node* temp1=head1;
       Node* temp2=head2;
       Node* dummy=new Node(-1);
       Node* curr=dummy;
       while(temp1!=NULL && temp2!=NULL)
       {
           if(temp1->data<temp2->data)
           {
               Node* newnode=new Node(temp1->data);
               curr->next=newnode;
               curr=newnode;
               if(temp1)temp1=temp1->next;
           }
           else if(temp1->data>temp2->data)
           {
               Node* newnode=new Node(temp2->data);
               curr->next=newnode;
               curr=newnode;
               if(temp2)temp2=temp2->next;
           }
           else
           {
               Node* newnode=new Node(temp1->data);
               curr->next=newnode;
               curr=newnode;
               if(temp1)temp1=temp1->next;
               Node* newnode1=new Node(temp2->data);
               curr->next=newnode1;
               curr=newnode1;
               if(temp2)temp2=temp2->next;
           }
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
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends