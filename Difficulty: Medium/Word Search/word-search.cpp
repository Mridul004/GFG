//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
 vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
 
 bool dfs(int i,int j,int k,vector<vector<char>> &mat,string &word)
 {
     if(k==word.size()) return 1;
     if(i<0||i>=mat.size()||j<0||j>=mat[0].size()||mat[i][j]!=word[k]) return 0;
     char temp=mat[i][j];
     mat[i][j]='0';
     for(auto &d:dir)
     {
         if(dfs(i+d[0],j+d[1],k+1,mat,word)) return 1;
     }
     mat[i][j]=temp;
     return 0;
 }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        stack<pair<char,pair<int,int>>> s;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,0,mat,word)) return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends