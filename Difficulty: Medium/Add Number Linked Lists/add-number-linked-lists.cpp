//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
       while (num1 && num1->data == 0) num1 = num1->next;
        while (num2 && num2->data == 0) num2 = num2->next;

        // If both lists are empty after removing leading zeroes, return a single node with 0
        if (!num1 && !num2) {
            return new Node(0);
        }

        // Reverse the input linked lists
        Node* temp1 = reverse(num1);
        Node* temp2 = reverse(num2);

        // Initialize a dummy node to simplify the addition process
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        int carry = 0;

        // Loop through both linked lists
        while (temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;

            if (temp1) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->data;
                temp2 = temp2->next;
            }

            // Create a new node with the sum modulo 10
            Node* newnode = new Node(sum % 10);
            curr->next = newnode;
            curr = newnode;

            // Update carry
            carry = sum / 10;
        }

        // If there is any carry left, add it as a new node
        if (carry != 0)
        {
            Node* newnode = new Node(carry);
            curr->next = newnode;
            curr = newnode;
        }

        // Reverse the result to get the final sum in the correct order
        return reverse(dummy->next);
    }

    // Function to reverse a linked list
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        while (head)
        {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends