// Problem: B. Most socially-distanced subsequence
// Contest: Codeforces - Codeforces Round 649 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1364/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 3:09PM 30/8/2023 */
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
		vector<int> ans ;
		ans.push_back(A[0]) ;
		for(int i = 1 ; i < N - 1 ; i ++){
			if(A[i] > A[i - 1] and A[i] > A[i + 1])
				ans.push_back(A[i]) ;
			else if(A[i] < A[i - 1] and A[i] < A[i + 1])
				ans.push_back(A[i]) ;
		}
		ans.push_back(A[N - 1]) ;
		cout << ans.size() << endl ;
		for(int i = 0 ; i < (int)ans.size() ; i ++)
			cout << ans[i] << " \n"[i + 1 == (int)ans.size()] ;
	}
}
/*
 Let's look at the expression in the problem for 3 numbers:
 If a>b and b>c or if a<b and b<c, |a−b|+|b−c|=|a−c| ;
 so it's never optimal to use a, b, and c in a row because you can use just a and c and
 achieve a shorter subsequence.
where a local minimum is an element less than its 2 adjacents, and a local maximum is
an element greater than it 2 adjacents
 from : Editorial .
 */