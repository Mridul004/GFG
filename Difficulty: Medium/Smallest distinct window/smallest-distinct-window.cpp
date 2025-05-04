//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        unordered_map<char,int> mp;
        set<char> s;
        int ans=INT_MAX;
        for(auto i:str) s.insert(i);
        int k=s.size();
        int i=0,j=0;
        while(j<str.length()){
            mp[str[j]]++;
            while(mp.size()>=k){
                ans=min(ans,j-i+1);
                mp[str[i]]--;
                if(mp[str[i]]==0) mp.erase(str[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends