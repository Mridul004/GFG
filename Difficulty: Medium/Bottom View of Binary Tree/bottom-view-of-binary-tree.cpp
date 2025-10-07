/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        int i=0;
        q.push(make_pair(root,i));
        
        while(!q.empty()){
            Node* t = q.front().first;
            i=q.front().second;
            m[i]=t->data;
            q.pop();
            if(t->left)q.push(make_pair(t->left,i-1));
            if(t->right)q.push(make_pair(t->right,i+1));
        }
        
        
        for(auto j:m){
            ans.push_back(j.second);
        }
        return ans;
    }
};