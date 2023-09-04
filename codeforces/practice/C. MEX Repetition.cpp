// Problem: C. MEX Repetition
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		int N ; int K ;
		cin >> N >> K ;
		vector<int>A(N + 1) ;
		int sum = (N*(N + 1)/2LL);
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ,sum -= A[i] ;
		A[N] =  sum ;
		K %= N + 1 ;
		rotate(A.begin(),A.end() - K,A.end()) ;
		for(int i = 0 ; i < N ; i ++)
			cout << A[i] << " \n"[i + 1 == N] ;
	}
}
