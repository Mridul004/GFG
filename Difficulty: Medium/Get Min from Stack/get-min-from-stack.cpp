//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  stack<int> s1;
  stack<int> s2;
  int mn;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            s2.push(x);
        }
        else{
            s1.push(x);
            s2.push(min(s2.top(),x));
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if(s1.empty()) return;
        s1.pop();
        s2.pop();
    }

    // Returns top element of the Stack
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        if(s2.empty()) return -1;
        return s2.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends