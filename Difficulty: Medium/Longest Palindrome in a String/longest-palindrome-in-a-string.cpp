//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool recur(int i,int j,string &s){
      if(i>=j) return 1;
      if(s[i]==s[j]) recur(i+1,j-1,s);
      else return 0;
  }
    string longestPalindrome(string &s) {
        int n=s.length();    
        int mx=INT_MIN,sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(recur(i,j,s)){
                    if(j-i+1>mx){
                        mx=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,mx);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends