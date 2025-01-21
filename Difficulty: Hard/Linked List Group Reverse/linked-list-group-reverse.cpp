//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node* temp=head;
        Node* prev=NULL;
        while(temp)
        {
            Node* knode=getknode(temp,k);
            if(knode==NULL)
            {
                Node* back=reverse(temp);
                prev->next=back;
                break;
            }
            Node* nextnode=knode->next;
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
    Node* getknode(Node* temp,int k)
    {
        k-=1;
        while(temp!=NULL && k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    Node* reverse(Node* temp)
    {
        Node* prev=NULL;
        while(temp!=NULL)
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
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends