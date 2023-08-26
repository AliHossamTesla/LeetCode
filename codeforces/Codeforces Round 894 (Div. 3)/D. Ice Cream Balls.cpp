// Problem: D. Ice Cream Balls
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 12:48pm 25/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t ;
	cin >> t ;
	while(t--){
		long long n ;
		cin >> n ;
		long long l = 0 , r = INT_MAX ;
		while(r - l > 1){
			long long mid = (r + l)/ 2 ;
			long long cr = (mid *(mid + 1))/2LL ;
			if(cr > n)
				r = mid ;
			else
				l = mid ;
		}
		cout << r + (n - (r*(r - 1)/2LL)) << endl ;
	}
}
/*
 * you binary search for the min number of (n)(n - 1)/2 can use but remember that you need it twice .
 */