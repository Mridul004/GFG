//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  static bool compare(string &a,string &b){
      return a.size()<b.size();
  }
    int longestStringChain(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans=1;
        sort(words.begin(),words.end(),compare);
        for(auto s:words){
            mp[s]=1;
            for(int i=0;i<s.length();i++){
                string ch=s.substr(0,i)+s.substr(i+1);
                if(mp.find(ch)!=mp.end()) mp[s]=max(mp[ch]+1,mp[s]);
            }
            ans=max(ans,mp[s]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends