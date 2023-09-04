// Problem: A. Prime Deletion
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1861/problem/A
// Memory Limit: 512 MB
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
		string s ;
		cin >> s ;
		pair<int,int>idx ;
		for(int i = 0 ; i < s.size() ; i ++){
			if(s[i] == '1')
				idx.first = i ;
			if(s[i] == '7')
				idx.second = i ;
		}
		cout << (idx.first < idx.second ? 17 : 71) << endl ;
	}
}
