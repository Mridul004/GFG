class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        if(arr[0]==0) return -1;
        int mr=arr[0],s=arr[0],count=1;
        for(int i=1;i<n;i++){
            if(i==n-1) return count;
            mr=max(mr,arr[i]+i);
            s--;
            if(s==0){
                count++;
                if(i>=mr) return -1;
                s=mr-i;
            }
        }
    }
};
