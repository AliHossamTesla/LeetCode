// Problem: B. Reach Median
// Contest: Codeforces - Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1037/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int N , S; cin >> N >> S ;
	vector<int>A(N) ;
	for(int i = 0 ; i < N ; i ++)
		cin >> A[i] ;
	sort(A.begin(), A.end()) ;
	if(A[N/2] == S) {
		cout << 0 << endl;
	}else if(A[N/2] < S){
		int ans = S - A[N/2] ;
		A[N/2] = S ;
		for(int i = N/2 + 1 ; i < N ; i ++){
			if(A[i] >= A[i - 1])
				continue ;
			ans += A[i - 1] - A[i] ;
			A[i] = A[i - 1] ;
		}
		cout << ans << endl ;
	}else{
		int ans = A[N/2] - S ;
		A[N/2] = S ;
		for(int i = N/2 - 1 ; i >= 0 ; i --){
			if(A[i] <= A[i + 1])
				continue ;
			ans += abs(A[i] - A[i + 1]) ;
			A[i] = A[i + 1] ;
		}
		cout << ans << endl ;
	}
}
