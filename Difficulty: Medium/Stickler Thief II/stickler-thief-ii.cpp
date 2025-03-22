//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<int> dp;
  int recur(vector<int>& arr){
     int n=arr.size();
        vector<int> dp(n);
        dp[n-1]=arr[n-1];
        if(n-2>=0){
            dp[n-2]=max(arr[n-2],arr[n-1]);
        }
        for(int i=n-3;i>=0;i--){
            dp[i]=max(dp[i+1],dp[i+2]+arr[i]);
        }
        return dp[0];
  }
    int maxValue(vector<int>& arr) {
        int n=arr.size();
        dp.resize(n+1,-1);
        vector<int> arr1,arr2;;
        for(int i=0;i<n-1;i++) arr1.push_back(arr[i]);
        for(int i=1;i<n;i++) arr2.push_back(arr[i]);
        return max(recur(arr1),recur(arr2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends