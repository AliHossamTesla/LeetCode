class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int duplicate = 1, vertical = 0, maxSlope = 0;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                } else if (dx == 0) {
                    vertical++;
                } else {
                    // Simplify slope (dy/dx) to a reduced fraction
                    int g = gcd(dy, dx);
                    dx /= g;
                    dy /= g;

                    // Ensure consistent representation for negative slopes
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    string slope = to_string(dy) + "/" + to_string(dx);
                    slopeCount[slope]++;
                    maxSlope = max(maxSlope, slopeCount[slope]);
                }
            }

            ans = max(ans, max(maxSlope, vertical) + duplicate);
        }

        return ans;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
