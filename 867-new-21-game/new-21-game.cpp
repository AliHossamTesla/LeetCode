using ftype = long double;

class Solution {
public:
    template <class T>
    struct BIT {
        int size;
        vector<T> bit, arr;
        BIT(int n) : size(n), bit(n + 1), arr(n) {}
        void add(int x, T v) {
            arr[x] += v;
            x++;
            for (; x <= size; x += x & -x) bit[x] += v;
        }
        T query(int b) {
            b++;
            T res = 0;
            for (; b > 0; b -= b & -b) res += bit[b];
            return res;
        }
        T q(int l, int r) {
            if (l > r) return 0;
            return query(r) - (l ? query(l - 1) : 0);
        }
    };

    double new21Game(int n, int k, int mx) {
        if (k == 0 || n >= k + mx) return 1.0;

        vector<ftype> dp(n + 1, 0);
        BIT<ftype> bt(n + 2);

        dp[0] = 1.0;
        bt.add(0, 1.0);

        double res = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = bt.q(max(0, i - mx), i - 1) / mx;  // sliding window avg
            if (i < k) {
                bt.add(i, dp[i]);  // can still draw
            } else {
                res += dp[i];      // terminal state
            }
        }

        return res;
    }
};
