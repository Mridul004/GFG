class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        int total = ((V-1)*(V))/2;  
        return total - edges.size();
    }
};
