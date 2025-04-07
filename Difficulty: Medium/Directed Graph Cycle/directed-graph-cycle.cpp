//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        vector<int>in(V);
        queue<int>q;
        int c=0;
        for(auto i:edges){
            int u=i[0],v=i[1];
            if(u==v) return true;
            in[v]++;
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i),c++;
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto i:adj[cur]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                    c++;
                }
            }
        }
        return (c<V);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends