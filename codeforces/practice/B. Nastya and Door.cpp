// Problem: B. Nastya and Door
// Contest: Codeforces - Codeforces Round 637 (Div. 2) - Thanks, Ivan Belonogov!
// URL: https://codeforces.com/problemset/problem/1341/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 12:56PM 30/8/2023 */
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
		int cnt = 0;
		for(int i = 1 ; i < K - 1 ; i ++){
			if(A[i] > A[i - 1] and A[i] > A[i + 1])
				cnt ++ ;
		}
		int ansCnt = cnt , ansL = 1 ;
		for(int i = K ; i < N ; i ++){
			if(A[i - 1] > A[i - 2] and A[i - 1] > A[i])
				cnt ++ ;
			if(A[i - K + 1] > A[i - K] and A[i - K + 1] > A[i - K + 2])
				cnt -- ;
			if(cnt > ansCnt)
				ansCnt = cnt , ansL = i - K + 2 ;
		}
		cout << ansCnt + 1 << " " << ansL << endl ;
	}
}