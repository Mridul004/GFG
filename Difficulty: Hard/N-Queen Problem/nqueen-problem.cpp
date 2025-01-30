//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool safe(int row,int col,vector<int> &v)
  {
      for(int i=0;i<row;i++) 
      {
          if(v[i]==col||abs(v[i]-col)==abs(i-row)) return 0;
      }
      return 1;
  }
  
  void recur(int row,vector<vector<int>> &ans,vector<int> &v,int n)
  {
      if(row==n)
      {
          ans.push_back(v);
          return;
      }
      for(int i=0;i<n;i++)
      {
          if(safe(row,i,v))
          {
              v.push_back(i);
              recur(row+1,ans,v,n);
              v.pop_back();
          }
      }
  }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> v;
        recur(0,ans,v,n);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<n;j++) ans[i][j]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends