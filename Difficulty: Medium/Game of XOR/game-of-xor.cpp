class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        if(arr.size()%2==0) return 0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(i%2==0) ans=ans^arr[i];
        }
        return ans;
    }
};