// Problem: F. Zero Remainder Sum
// Contest: Codeforces - Codeforces Round 677 (Div. 3)
// URL: https://codeforces.com/contest/1433/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define Wady ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
const int N = 75 ;
const int oo = 1e9 ;
ll n, k, m;
int grid[N][N] ;
int dp[N][N][N][N] ;
void doYourJop()
{
	cin >> n >> m >> k ;
	for(int i = 0 ;i < n ; i ++)
		for(int j = 0 ;j < m ; j ++)
			cin >> grid[i][j] ;
	for(int i = 0 ; i < N ; i ++)
		for(int j = 0 ; j < N ; j ++)
			for(int cnt = 0 ; cnt < N ; cnt ++)
				for(int rem = 0 ; rem < N ; rem ++)
					dp[i][j][cnt][rem] = -oo ;
	dp[0][0][0][0] = 0 ;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			for(int cnt = 0 ; cnt < m/2 + 1 ; cnt ++){
				for(int rem = 0 ; rem < k ; rem ++){
					if(dp[i][j][cnt][rem] == -oo)
							continue ;
					int ni = (j == m - 1 ? i + 1 : i);
					int nj = (j == m - 1 ? 0 : j + 1);
					if (i != ni) {
						dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
					} else {
						dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
					}
					if (cnt + 1 <= m / 2) {
						int nrem = (rem + grid[i][j]) % k;
						if (i != ni) {
							dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + grid[i][j]);
						} else {
							dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + grid[i][j]);
						}
					}
				}
			}
		}
	}
	cout << max(0,dp[n][0][0][0]) << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	int testCase = 1 ;
	// cin >> testCase ;
	while(testCase --)
		doYourJop();
	return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * DON'T assume thing he doesn't say .
 * ANALYZE each idea you have thoroughly.
 */