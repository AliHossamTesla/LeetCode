// Problem: B. Nastia and a Good Array
// Contest: Codeforces - Codeforces Round 720 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1521/B
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
		int N ;
		cin >> N ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		int idx = (min_element(A.begin(), A.end()) - A.begin()) ;
		cout << N - 1 << endl ;
		for(int i = 0 ; i < N ; i ++)
			if(i != idx)
				cout << i + 1 << " " << idx + 1 << " " << A[idx] + abs(i - idx) << " " << A[idx] << endl ;
	}
}
