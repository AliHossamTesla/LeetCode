// Problem: G. Sorting Pancakes
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:07pm 24/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	vector<int>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i] ;
	vector<int>pref(n + 1) ;
	for(int i = 1 ; i <= n ; i ++)
		pref[i] = pref[i - 1] + v[i - 1] ;
	vector<vector<int>>dp(n + 1,vector<int>(m + 1,1e9)) ;
	dp[0][0] = 0 ;
	for (int x = m; x >= 0; x--) {
		for (int j = 0; j <= m - x; j++) {
			for (int i = 0; i < n && i * x <= j; i++) {
				dp[i + 1][j + x] = std::min(dp[i + 1][j + x], dp[i][j] + std::abs(j - pref[i]));
			}
		}
	}
	cout << dp[n][m] << endl ;
}
/*
 * can't explain :< ;
 * to problem : https://www.youtube.com/watch?v=pZ8b_UemSEo&ab_channel=%D8%A7%D8%AA%D8%B9%D9%84%D9%85%D8%A7%D9%88%D9%86%D9%84%D8%A7%D9%8A%D9%86
 */