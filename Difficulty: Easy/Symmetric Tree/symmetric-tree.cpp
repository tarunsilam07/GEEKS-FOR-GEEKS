/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool solve(Node* r1, Node* r2){
        if(r1==NULL && r2==NULL) return 1;
        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)) return 0;
        return ((r1->data==r2->data) && solve(r1->left, r2->right) 
        && solve(r1->right, r2->left));
    }
    
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return 1;
	    return solve(root->left, root->right);
    }
};