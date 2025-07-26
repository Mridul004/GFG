class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        n/=3;
        set<int> s;
        unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
            if(mp[i]>n) s.insert(i);
        }
        vector<int> v;
        for(auto i:s) v.push_back(i);
        return v;
    }
};