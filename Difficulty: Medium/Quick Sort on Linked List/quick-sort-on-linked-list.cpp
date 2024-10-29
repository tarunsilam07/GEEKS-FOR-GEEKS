//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    struct Node* quickSort(struct Node* head) {
        vector<int>arr;
        Node* temp=head;
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        vector<int>ans= helper(arr);
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        for(auto it:ans){
            Node* newnode=new Node(it);
            curr->next=newnode;
            curr=newnode;
        }
        return dummy->next;
    }
    vector<int> helper(vector<int>&arr){
         if (arr.size() <= 1) {
        return arr;
    }

    int pivot = arr[arr.size() / 2];
    std::vector<int> left, right, equal;

    for (int element : arr) {
        if (element < pivot) {
            left.push_back(element);
        } else if (element > pivot) {
            right.push_back(element);
        } else {
            equal.push_back(element);
        }
    }

    std::vector<int> sortedLeft = helper(left);
    std::vector<int> sortedRight = helper(right);

    sortedLeft.insert(sortedLeft.end(), equal.begin(), equal.end());
    sortedLeft.insert(sortedLeft.end(), sortedRight.begin(), sortedRight.end());

    return sortedLeft;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

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
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends