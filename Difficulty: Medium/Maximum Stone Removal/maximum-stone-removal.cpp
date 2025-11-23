class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        map<int, vector<int>> row;

        // Map column -> list of rows
        map<int, vector<int>> col;

        // Build adjacency info
        for (auto &e : stones) {
            row[e[0]].push_back(e[1]);
            col[e[1]].push_back(e[0]);
        }

        set<pair<int,int>> vis;

        int ans = 0;

        
        for (auto &e : stones) {
            int x = e[0];
            int y = e[1];

            if (vis.count({x, y}) == 0) {

                int cnt = 0;
                queue<pair<int,int>> q;

                q.push({x, y});
                vis.insert({x, y});

                while (!q.empty()) {
                    auto [i, j] = q.front();
                    q.pop();
                    cnt++;

                    // All stones in same row
                    for (auto &yy : row[i]) {
                        if (!vis.count({i, yy})) {
                            vis.insert({i, yy});
                            q.push({i, yy});
                        }
                    }

                    // All stones in same column
                    for (auto &xx : col[j]) {
                        if (!vis.count({xx, j})) {
                            vis.insert({xx, j});
                            q.push({xx, j});
                        }
                    }
                }

                // You can remove (cnt - 1) stones
                ans += (cnt - 1);
            }
        }

        return ans;
    }
};