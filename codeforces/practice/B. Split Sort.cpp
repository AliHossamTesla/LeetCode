// Problem: B. Split Sort
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 10:31PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N ;
		cin >> N ;
		vector<int>A(N + 1) ;
		for(int i = 1 ; i <= N ; i ++){
			int val ; cin >> val ;
			A[val] = i ;
		}
		int cnt = 0 ;
		for(int i = N ; i > 0 ;i--){
			int cr = i ;
			while(cr > 0 and A[cr - 1] < A[cr])
				cr -- ;
			i = cr ;
			cnt ++ ;
		}
		cout << cnt - 1 << endl ;
	}
}
