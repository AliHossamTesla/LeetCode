// Problem: D. Array and Operations
// Contest: Codeforces - Codeforces Round 760 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1618/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 10:22PM 2/9/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N , K ; cin >> N >> K ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		sort(A.rbegin(), A.rend()) ;
		int ans = 0 ;
		for(int i = 0 ; i < K ; i ++)
			ans += A[i + K]/A[i] ;
		ans += accumulate(A.begin() + 2*K , A.end(),0LL) ;
		cout << ans << endl ;
	}
}
