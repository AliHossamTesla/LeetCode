// Problem: A. Ahahahahahahahaha
// Contest: Codeforces - Codeforces Round 669 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1407/A
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
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N ;
		cin >> N ;
		vector<int>v(N) ;
		int cnt1 = 0,cnt0 = 0  ;
		for(int i = 0 ; i < N ; i ++)
			cin >> v[i] , cnt1 += v[i] ,cnt0 += (v[i] == 0);
		if(cnt1 <= N/2){
			cout << N - cnt1 << endl ;
			for(int i = 0 ; i < N ; i ++)
				if(!v[i])
					cout << 0 << " " ;
			cout << endl ;
		}else{
			int flag = 0 ;
			if(cnt1&1)
				flag = 1 ;
			cout << N - cnt0 - flag << endl ;
			for(int i = 0 ; i < N ; i ++)
				if(v[i]){
					if(flag)
						flag = 0 ;
					else
						cout << v[i] << " " ;
				}
			cout << endl ;
		}

	}
}