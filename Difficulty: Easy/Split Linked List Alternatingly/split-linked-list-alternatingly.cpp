//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
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

class Solution {
  public:
    // Function to split a linked list into two lists alternately
   vector<Node*> alternatingSplitList(struct Node* head) {
    vector<Node*> ans;
    if (head == NULL) return {head, NULL};

    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);
    Node* curr1 = dummy1;
    Node* curr2 = dummy2;
    Node* temp1 = head;
    Node* temp2 = (head->next) ? head->next : NULL;

    while (temp1) {
        Node* newnode1 = new Node(temp1->data);
        curr1->next = newnode1;
        curr1 = newnode1;
        
        if (temp1->next && temp1->next->next)
            temp1 = temp1->next->next;
        else
            temp1 = NULL;
    }

    while (temp2) {
        Node* newnode2 = new Node(temp2->data);
        curr2->next = newnode2;
        curr2 = newnode2;
        
        if (temp2->next && temp2->next->next)
            temp2 = temp2->next->next;
        else
            temp2 = NULL;
    }

    ans.push_back(dummy1->next);
    ans.push_back(dummy2->next);

    return ans;
}

};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends