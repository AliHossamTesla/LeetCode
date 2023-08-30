// Problem: B. Ternary Sequence
// Contest: Codeforces - Codeforces Round 665 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1401/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std ;
#define int long long
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int v[2][3] ;
		cin >> v[0][0] >> v[0][1] >> v[0][2] ;
		cin >> v[1][0] >> v[1][1] >> v[1][2] ;
		v[1][2] = max(0LL,v[1][2] - v[0][0]) ;
		if(v[1][2] == 0)
			cout << 2*min(v[0][2],v[1][1]) << endl ;
		else{
			if(v[0][2] > v[1][2])
				cout << 2*min(v[0][2] - v[1][2],v[1][1]) << endl ;
			else
				cout << -2*min(v[1][2] - v[0][2],v[0][1]) << endl ;
		}
	}
}