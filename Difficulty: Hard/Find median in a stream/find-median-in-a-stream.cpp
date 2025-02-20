//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> leftmax;
        priority_queue<int,vector<int>,greater<int>> rightmin;
        for(int i=0;i<arr.size();i++){
            leftmax.push(arr[i]);
            int ele=leftmax.top();
            rightmin.push(ele);
            leftmax.pop();
            if(rightmin.size()>leftmax.size()){
                int el=rightmin.top();
                leftmax.push(el);
                rightmin.pop();
            }
        
        double median;
        if(leftmax.size()==rightmin.size())
        median=(double)(leftmax.top()+rightmin.top())/2;
        else
        median=leftmax.top();
        
        ans.push_back(median);
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends