class Solution {
  public:
    string findLargest(vector<int> &arr) {
        vector<string> s;
        for(auto i:arr) s.push_back(to_string(i));
        sort(s.begin(),s.end(),[](const string &a,const string &b){
            return a+b>b+a;
        });
        string ans="";
        for(auto i:s) ans+=i;
        if(ans[0]=='0') return "0";
        return ans;
    }
};