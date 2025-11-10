class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int sold = 0;       
        int held = -arr[0];
        int rest = 0;        
        for (int i = 1; i < n; i++) {
            int prev_sold = sold;
            sold = held + arr[i];
            held = max(held, rest - arr[i]);
            rest = max(rest, prev_sold);
        }
        return max(sold, rest);
    }
};