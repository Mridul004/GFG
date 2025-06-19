class Solution {
  public:
    string caseSort(string& s) {
        unordered_map<int,int> mp;
        vector<char> cap,small;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>=65&&s[i]<=90){
                mp[i]++;
                cap.push_back(s[i]);
            }
            else small.push_back(s[i]);
        }
        sort(cap.begin(),cap.end());
        sort(small.begin(),small.end());
        string str="";
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(mp[i]){
                str+=cap[a];
                a++;
            }
            else{
                str+=small[b];
                b++;
            }
            
        }
        return str;
    }
};