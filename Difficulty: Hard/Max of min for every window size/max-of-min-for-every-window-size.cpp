class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n),right(n),ans(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) left[i]=-1;
            else left[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&arr[s.top()]>=arr[i]) s.pop();
            if(s.empty()) right[i]=n;
            else right[i]=s.top();
            s.push(i);
        }
        vector<int> mn(n+1,0);
        for(int i=0;i<n;i++){
            int len=right[i]-left[i]-1;
            mn[len]=max(mn[len],arr[i]);
        }
        for(int i=n-1;i>0;i--){
            mn[i]=max(mn[i],mn[i+1]);
        }
        for(int i=0;i<n;i++) ans[i]=mn[i+1];
        return ans;
    }
};