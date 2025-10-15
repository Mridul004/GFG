/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void recur(Node * root,priority_queue<int> &pq,int k){
        if(root==nullptr) return;
        pq.push(root->data);
        if(pq.size()>k) pq.pop();
        recur(root->left,pq,k);
        recur(root->right,pq,k);
    }
    int kthSmallest(Node *root, int k) {
        priority_queue<int> pq;
        recur(root,pq,k);
        if(pq.size()<k) return -1;
        return pq.top();
    }
};