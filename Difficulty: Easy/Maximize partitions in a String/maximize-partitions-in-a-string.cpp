//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) mp[s[i]]=i;
        int mx=0,count=0;
        for(int i=0;i<s.length();i++){
            mx=max(mx,mp[s[i]]);
            if(i==mx) count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends