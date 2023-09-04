// Problem: B. Paranoid String
// Contest: Codeforces - Codeforces Round 800 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1694/B
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
		int N ; cin >> N ;
		string  A ;
		cin >> A ;
		int ans = (int)A.size() ;
		for(int i = 1 ; i < N ; i ++)
			if(A[i] != A[i - 1])
				ans += i ;
		cout << ans << endl ;
	}
}