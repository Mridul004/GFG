class Solution {
  public:
    int romanToDecimal(string &s) {
        int ans = 0;
        int prev = 0;
        unordered_map<char, int> entry;
        entry['I'] = 1;
        entry['V'] = 5;
        entry['X'] = 10;
        entry['L'] = 50;
        entry['C'] = 100;
        entry['D'] = 500;
        entry['M'] = 1000;
        for(auto i : s) {
            int roman = entry[i];
            if( roman > prev) ans += roman - 2*prev;
            else ans += roman;
            prev = roman;
        }
        return ans;
    }
};