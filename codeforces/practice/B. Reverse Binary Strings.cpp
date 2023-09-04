// Problem: B. Reverse Binary Strings
// Contest: Codeforces - Educational Codeforces Round 97 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1437/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 6:02Am 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N ; cin >> N ;
		string s ;
		cin >> s ;
		int cnt = 1;
		for(int i =0 ; i < N ; i ++)
			cnt += (s[i] == s[i - 1]) ;
		cout << cnt/2 << endl ;
	}
}