// Problem: D. Sorting By Multiplication
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1861/problem/D
// Memory Limit: 256 MB
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
		int N ;
		cin >> N ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		int ans = 0 ;
		for(int i = 0 ; i < N - 1 ; i ++)
			ans += (A[i] >= A[i + 1]) ;
		int cr = ans ;
		for(int i = 1 ; i < N ; i ++){
			cr -= (A[i - 1] >= A[i]) ;
			ans = min(ans,cr + 1) ;
			cr += (A[i - 1] <= A[i]) ;
		}
		cout << ans << endl ;
	}
}
