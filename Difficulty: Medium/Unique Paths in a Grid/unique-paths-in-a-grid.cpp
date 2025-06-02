class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1) return 0;
        vector<int> dp(m+1,0);
        dp[1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]==0) dp[j]=dp[j]+dp[j-1];
                else dp[j]=0;
            }
        }
        return dp[m];
    }
};