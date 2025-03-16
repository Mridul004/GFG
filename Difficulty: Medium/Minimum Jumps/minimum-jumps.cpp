//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  #define pp pair<int,int>
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        if(arr[0]==0) return -1;
        int mr=arr[0],s=arr[0],count=1;
        for(int i=1;i<n;i++){
            if(i==n-1) return count;
            mr=max(mr,arr[i]+i);
            s--;
            if(s==0){
                count++;
                if(i>=mr) return -1;
                s=mr-i;
            }
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends