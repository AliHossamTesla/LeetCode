// Problem: C. Kill the Monster
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1633/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int hc , dc , hm , dm , k , w , a ;
		cin >> hc >> dc >> hm >> dm >> k >> w >> a ;
		bool ok = 0 ;
		for(int i = 0 ; i <= k ;i ++){
			int hc_in = hc + i * a , dc_in = dc + (k - i)*w ;
			if((hm + dc_in - 1)/dc_in <= (hc_in + dm - 1)/dm)
				ok = 1 ;
		}
		cout << (ok ? "YES\n" : "NO\n") ;
	}
}