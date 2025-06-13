class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int l=1,r=*max_element(arr.begin(),arr.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            double sum=0;
            for(int i=0;i<arr.size();i++){
                sum+=ceil((double)arr[i]/(double)mid);
            }
            if(sum<=k) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};