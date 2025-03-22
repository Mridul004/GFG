//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  vector<int> dp;
  int recur(int i,vector<int>& arr){
      if(i>=arr.size()) return 0;
      int pick=0,npick=0;
      if(dp[i]!=-1) return dp[i];
      pick=arr[i]+recur(i+2,arr);
      npick=recur(i+1,arr);
      return dp[i]=max(pick,npick);
  }
    int findMaxSum(vector<int>& arr) {
        int n=arr.size();
        dp.resize(n+1,-1);
        return recur(0,arr);
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends