// Problem: A. Channel
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 3:09PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N , A , Q ;
		cin >> N >> A >> Q ;
		string s ; cin >> s ;
		if(N == A){
			cout << "YES\n" ;
			continue ;
		}
		int cr_statue = A ,cnt = 0;
		bool ok = 0 ;
		for(int i = 0 ; i < Q ; i ++){
			if(s[i] == '+')
				cr_statue ++ ;
			else
				cr_statue -- ;
			cnt += (s[i] == '+') ;
			if(cr_statue == N)
				ok = 1 ;
		}
		cout << (ok ? "YES\n" : (cnt + A >= N ? "MAYBE\n" : "NO\n")) ;
	}
}
