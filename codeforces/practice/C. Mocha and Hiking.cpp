// Problem: C. Mocha and Hiking
// Contest: Codeforces - Codeforces Round 738 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1559/C
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
		int N ;
		cin >> N ;
		vector<int>A[2] ;
		for(int i = 1 ; i <= N ; i ++){
			int val ; cin >> val ;
			A[val].push_back(i) ;
		}
		sort(A[0].begin(), A[0].end()) ;sort(A[1].begin(), A[1].end()) ;
		int fr = -1 ;
		for(int i = 0 ; i < A[0].size() ; i ++){
			auto to = upper_bound(A[1].begin(),A[1].end(),A[0][i]) ;
			if(to != A[1].end() and *to - 1 == A[0][i])
				fr = A[0][i] ;
		}
		if(fr == -1){
			if(A[1].size() != 0 and A[1][0] == 1){
				cout << N + 1 << " " ;
				for(int i = 1 ; i <= N ; i ++)
					cout << i << " \n"[i == N] ;
			}else if(A[0].size() != 0 and A[0].back() == N){
				for(int i = 1 ; i <= N ; i ++)
					cout << i << " " ;
				cout << N + 1 << endl ;
			}else
				cout << -1 << endl ;
		}else{
			for(int i = 1 ; i <= N ; i ++){
				cout << i << " " ;
				if(i == fr)
					cout << N + 1 << " " ;
			}
			cout << endl ;
		}
	}
}