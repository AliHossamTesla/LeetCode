// Problem: C. Alternating Subsequence
// Contest: Codeforces - Codeforces Round 636 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1343/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		for(int i = 0; i < N ; i ++)
			cin >> A[i] ;
		pair<int,int>neg,pos ;
		for(int i = 0 ; i < N ; i ++){
			if(A[i] > 0)
				neg = max(neg, make_pair(pos.first + 1,pos.second + A[i])) ;
			else
				pos = max(pos, make_pair(neg.first + 1,neg.second + A[i])) ;
		}
		cout << max(neg,pos).second << endl ;
	}
}