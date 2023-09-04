// Problem: B. Shuffle
// Contest: Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1366/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 10:02Am 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N , X , M ;
		cin >> N >> X >> M ;
		int L = X , R = X ;
		while(M--){
			int l , r ; cin >> l >> r ;
			if(l <= R and r >= L)
				R = max(R,r) , L = min(L,l) ;
		}
		cout << R - L + 1 << endl ;
	}
}