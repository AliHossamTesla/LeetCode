// Problem: A. Sequence with Digits
// Contest: Codeforces - Codeforces Round 643 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1355/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int A , N ;
		cin >> A >> N ;
		function<int(int,int)> solve = [&](int A,int idx)->int{
			if(idx == N)
				return A ;
			string s = to_string(A) ;
			int mn = 10 , mx = 0 ;
			for(auto c : s)
				mn = min(mn,(c - '0')*1LL) , mx = max(mx,(c - '0')*1LL) ;
			if(mn == 0)
				return A ;
			return solve(A+(mn*mx),idx + 1) ;

		};
		cout << solve(A,1) << endl ;
	}
}