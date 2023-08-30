// Problem: B. Maximum Product
// Contest: Codeforces - Codeforces Round 670 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1406/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
		int N ; cin >> N ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		sort(A.begin(),A.end()) ;
		int option1 = A[N - 1]*A[N - 2]*A[N - 3]*A[N - 4]*A[N - 5] ;
		int option2 = A[N - 1]*A[N - 2]*A[N - 3]*A[0]*A[1] ;
		int option3 = A[N - 1]*A[0]*A[1]*A[2]*A[3] ;
		cout << max({option1,option2,option3}) << endl ;
	}
}