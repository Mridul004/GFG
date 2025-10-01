class Solution {
  public:
  set<vector<int>> ans;
  void recur(int i,vector<int> &arr){
      if(i==arr.size()){
          ans.insert(arr);
          return;
      }
      for(int j=i;j<arr.size();j++){
          swap(arr[i],arr[j]);
          recur(i+1,arr);
          swap(arr[i],arr[j]);
      }
  }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        recur(0,arr);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};