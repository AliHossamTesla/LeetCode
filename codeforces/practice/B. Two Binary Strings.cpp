// Problem: B. Two Binary Strings
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1861/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 8:32PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		string A , B ;
		cin >> A >> B ;
		bool ok = 0 ;
		for(int i = 0 ; i < A.size() - 1 ; i ++)
			if(A[i] == '0' and A[i + 1] == '1' and B[i] == '0' and B[i + 1] == '1')
				ok = 1 ;
		cout << (ok ? "YES\n" : "NO\n") ;
	}
}
