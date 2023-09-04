// Problem: D. Masha and a Beautiful Tree
// Contest: Codeforces - Codeforces Round 826 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1741/D
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
		int N ; cin >> N ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		int cnt = 0 ;
		if(N == 1){
			cout << 0 << endl ;
			continue ;
		}
		function<void(int,int)> solve = [&](int l,int r)->void{
			if(r - l == 1){
				if(A[r] < A[l]){
					swap(A[l],A[r]) ;
					cnt ++ ;
				}
				return ;
			}
			int mid = l + (r - l)/2 ;
			solve(l , mid) ; solve(mid + 1,r) ;
			if(A[l] > A[mid + 1]){
				cnt ++ ;
				for(int i = l ; i <= mid ; i ++)
					swap(A[i],A[mid + (i - l) + 1]) ;
			}
		};
		solve(0,N - 1) ;
		bool bad = 0 ;
		for(int i = 1 ;i < N ; i ++)
			if(A[i] < A[i - 1])
				bad = 1 ;
		cout << (bad ? -1 : cnt) << endl ;
	}
}
