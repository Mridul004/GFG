//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
         int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2 = s2.substr(1);
    }
    
    int n = s1.size(), m = s2.size();
    vector<int> result(n + m, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }
    
    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    
    if (product.empty()) return "0";
    if (sign == -1) product.insert(product.begin(), '-');
    
    return product;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends