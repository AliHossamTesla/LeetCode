// Problem: C. Coin Rows
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1555/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 12:56PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N ; cin >> N ;
		int A[2][N] ;
		for(int i = 0 ; i < N ; i ++)
				cin >> A[0][i] ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[1][i] ;
		vector<int>pref(N,0),sef(N,0) ;
		pref[0] = A[0][0] ;
		for(int i = 1 ; i < N ; i ++)
			pref[i] = pref[i - 1] + A[0][i] ;
		sef[N - 1] = A[1][N - 1] ;
		for(int i = N - 1 ; i > 0 ; i --)
			sef[i - 1] = sef[i] + A[1][i - 1] ;
		int ans = min(sef[0] - sef[N - 1],pref[N - 1] - pref[0]) , breakPoint = -1 ;
		for(int i = 1 ; i < N - 1 ; i ++){
			int cr = max(sef[0] - sef[i],pref[N - 1] - pref[i]) ;
			ans = min(ans,cr) ;
		}
		cout << ans << endl ;
	}
}