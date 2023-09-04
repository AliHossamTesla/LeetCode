// Problem: C. Number of Pairs
// Contest: Codeforces - Codeforces Round 725 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1538/C
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
		int N , L , R ;
		cin >> N >> L >> R ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		sort(A.begin(), A.end()) ;
		int ans = 0 ;
		for(int i = 0 ; i < N ; i ++){
			int l = L - A[i] , r = R - A[i] ;
			if(r < 0)
				break ;
			ans += (upper_bound(A.begin(), A.end(),r) - lower_bound(A.begin(), A.end(),l) - (A[i] >= l and A[i] <= r)) ;
		}
		cout << ans/2 << endl ;
	}
}
