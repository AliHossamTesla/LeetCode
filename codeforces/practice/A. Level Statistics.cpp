// Problem: A. Level Statistics
// Contest: Codeforces - Educational Codeforces Round 85 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1334/A
// Memory Limit: 256 MB
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
		pair<int,int>prev = {0,0};
		bool bad = 0 ;
		for(int i = 0 ; i < N ; i ++){
			int plays , clears ;
			cin >> plays >> clears ;
			if(plays < prev.first or clears < prev.second)
				bad = 1 ;
			if((plays - prev.first) < (clears - prev.second))
				bad = 1 ;
			prev = {plays,clears};
		}
		cout << (bad ? "NO\n" : "YES\n") ;
	}
}