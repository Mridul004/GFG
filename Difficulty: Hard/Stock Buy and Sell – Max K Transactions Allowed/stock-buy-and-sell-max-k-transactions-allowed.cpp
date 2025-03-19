//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<vector<vector<int>>> dp;
  int recur(int i,vector<int>& prices,int k,bool canbuy){
      if(i==prices.size()||k==0) return 0;
      if(dp[i][k][canbuy]!=-1) return dp[i][k][canbuy];
      int pick=0,npick=0;
      if(canbuy){
          pick=recur(i+1,prices,k,0)-prices[i];
          npick=recur(i+1,prices,k,1);
      }
      else{
          pick=recur(i+1,prices,k-1,1)+prices[i];
          npick=recur(i+1,prices,k,0);
      }
      return dp[i][k][canbuy]=max(pick,npick);
  }
    int maxProfit(vector<int>& prices, int k) {
        bool canbuy=1;
        int n=prices.size();
        dp.resize(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return recur(0,prices,k,canbuy);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends