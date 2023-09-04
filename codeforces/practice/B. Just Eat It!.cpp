// Problem: B. Just Eat It!
// Contest: Codeforces - Codeforces Round 613 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1285/B
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
		int N ;
		cin >> N ;
		vector<int>A(N) ;
		int sum = 0 ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ,sum += A[i];
		auto fn = [&](int start,int end)->int {
			int maxSoFar = INT_MIN , maxTillHere = 0 ;
			for(int i = start ; i < end  ; i ++){
				maxTillHere += A[i] ;
				if(maxTillHere > maxSoFar)
					maxSoFar = maxTillHere ;
				if(maxTillHere < 0)
					maxTillHere = 0 ;
			}
			return maxSoFar ;
		};
		int maxSegSum = max(fn(0,N - 1),fn(1,N)) ;
		cout << (sum > maxSegSum ? "YES\n" : "NO\n") ;
	}
}
/*
 * find the largest segment sum by (Kadane’s Algorithm) source :-
 * https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 */