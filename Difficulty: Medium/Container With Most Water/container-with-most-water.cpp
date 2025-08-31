class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        int i=0,j=n-1,ans=0;
        while(i<j)
        {
            ans=max(ans,min(arr[i],arr[j])*(j-i));
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        return ans;
    }
};