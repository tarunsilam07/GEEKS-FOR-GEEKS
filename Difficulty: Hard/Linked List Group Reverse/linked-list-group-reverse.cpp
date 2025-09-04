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

