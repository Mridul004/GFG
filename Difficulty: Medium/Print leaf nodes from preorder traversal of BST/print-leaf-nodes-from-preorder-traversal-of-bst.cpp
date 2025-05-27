class Solution {
  public:
  void solve(vector<int> preorder,int low,int high,vector<int> &v){
        if(low>high){
            return;
        }
        if(low==high){
            v.push_back(preorder[low]);
            return;
        }
        int j=low+1;
        while(j<=high && preorder[j]<preorder[low]){
            j++;
        }
        solve(preorder,low+1,j-1,v);
        solve(preorder,j,high,v);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> v;
        int N=preorder.size();
        solve(preorder,0,N-1,v);
        return v;
    }
};