class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        vector<int> a;

        // Flatten the board into 1D array
        for (int i = n - 1, sgn = 1; i >= 0; --i) {
            if (sgn) {
                for (int j = 0; j < n; ++j) {
                    a.push_back(b[i][j]);
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    a.push_back(b[i][j]);
                }
            }
            sgn = 1 - sgn;
        }

        queue<int> q;
        q.push(0);
        vector<int> dist(n * n, -1);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n * n - 1) return dist[i];

            for (int j = 1; j <= 6; ++j) {
                int ni = i + j;

                if (ni < n * n){
                    if (a[ni] != -1) {
                        ni = a[ni] - 1;
                    }

                    if (dist[ni] == -1) {
                        dist[ni] = dist[i] + 1;
                        q.push(ni);
                    }
                }
            }
        }

        return -1;
    }
};
