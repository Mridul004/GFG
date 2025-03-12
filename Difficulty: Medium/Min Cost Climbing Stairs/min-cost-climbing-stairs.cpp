//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
  vector<int> dp;
  int recur(int idx,vector<int> &cost){
      if(idx>=cost.size()) return 0;
      if(dp[idx]!=-1) return dp[idx];
      int pick=cost[idx]+recur(idx+1,cost);
      int notpick=cost[idx]+recur(idx+2,cost);
      return dp[idx]=min(pick,notpick);
  }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(),-1);
        return min(recur(0,cost),recur(1,cost));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends