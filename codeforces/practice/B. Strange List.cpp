// Problem: B. Strange List
// Contest: Codeforces - Codeforces Round 694 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1471/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		int N , X ;
		cin >> N >> X ;
		vector<pair<int,int>>v(N) ;
		bool ok = 1 ;
		for(int i = 0 ;i < N ; i ++)
			cin >> v[i].first , v[i].second = 1 ;
		for(int i = 0 ; i < (int)v.size() ; i ++){
			if(v[i].first % X == 0)
				v.push_back({v[i].first/X,v[i].second*X}) ;
			else
				break ;
		}
		int sum = 0 ;
		for(int i = 0 ; i < (int)v.size() ; i ++)
			sum += v[i].first * v[i].second ;
		cout << sum << endl ;
	}
}