//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        int n = s.length();
        stack<int> numst;
        stack<string> strst;
        string currStr = "";
        int num = 0;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); 
            } 
            else if (s[i] == '[') {
                numst.push(num);  
                strst.push(currStr); 
                num = 0; 
                currStr = "";  
            } 
            else if (s[i] == ']') {
                string temp = currStr;
                int repeat = numst.top();
                numst.pop();
                
                currStr = strst.top(); 
                strst.pop(); 
                
                while (repeat--) {
                    currStr += temp;
                }
            } 
            else {
                currStr += s[i]; 
            }
        }
        return currStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends