class Solution {
  public:
  void recur(int i,vector<vector<string>> &ans,vector<string> &v,string s){
      if(i>=s.size()){
          ans.push_back(v);
          return;
      }
      for(int j=i;j<s.size();j++){
            string p = s.substr(i, j-i+1);
            string r = p;
            reverse(p.begin(), p.end());
            if(p==r){
                v.push_back(p);
                recur(j+1,ans,v,s);
                v.pop_back();
            }
        }
  }
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string> v;
        recur(0,ans,v,s);
        return ans;
    }
};