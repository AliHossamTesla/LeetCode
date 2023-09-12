// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 5:26pm 2/9/2023 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    if (grid[0][0] == '*' or grid[N - 1][N - 1] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(N, vector<int>(N, -1));
    function<int(int, int)> solve = [&](int i, int j) -> int
    {
        if (i == 0 and j == 0)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int opt1 = 0, opt2 = 0;
        if (j - 1 >= 0 and grid[i][j - 1] != '*')
            opt1 = solve(i, j - 1);
        if (i - 1 >= 0 and grid[i - 1][j] != '*')
            opt2 = solve(i - 1, j);
        return dp[i][j] = (opt1 + opt2) % MOD;
    };
    cout << solve(N - 1, N - 1) << endl;
}