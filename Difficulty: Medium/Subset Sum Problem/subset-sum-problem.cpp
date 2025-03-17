//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool recur(int idx,vector<int>& arr,int sum,vector<vector<int>>& dp){
      if(idx==arr.size()) return sum==0;
      if(dp[idx][sum]!=-1) return dp[idx][sum];
      int pick=0;
      if(arr[idx]<=sum) pick=recur(idx+1,arr,sum-arr[idx],dp);
      int npick=recur(idx+1,arr,sum,dp);
      return dp[idx][sum]=pick||npick;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return recur(0,arr,sum,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends