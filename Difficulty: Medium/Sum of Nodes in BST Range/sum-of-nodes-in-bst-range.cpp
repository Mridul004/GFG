/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL) return 0;
        
        int ans = 0;
        if (root->data >= l && root->data <= r) {
            ans += root->data;
        }
        if (root->data > l) {
            ans += nodeSum(root->left, l, r);
        }
        if (root->data < r) {
            ans += nodeSum(root->right, l, r);
        }
        return ans;
    }
};
