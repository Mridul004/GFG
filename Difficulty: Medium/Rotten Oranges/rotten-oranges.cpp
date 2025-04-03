//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        int ans=0,count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                    count++;    
                }
                else if(mat[i][j]) count++;
            }
        }
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int t=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            ans=max(ans,t);
            count--;
            for(auto &d:dir){
                int x1=x+d[0];
                int y1=y+d[1];
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&!vis[x1][y1]&&mat[x1][y1]==1){
                    vis[x1][y1]=1;
                    q.push({t+1,{x1,y1}});
                }
            }
        }
        if(count==0) return ans;
        else return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends