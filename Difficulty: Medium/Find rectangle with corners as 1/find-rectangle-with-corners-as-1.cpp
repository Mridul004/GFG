class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    if(mat[i][j]==1&&mat[i][k]==1){
                        if(mp.find(j)!=mp.end()&&mp[j].find(k)!=mp[j].end()) return 1;
                        else mp[j].insert(k);
                    }
                }
            }
        }
        return 0;
    }
};