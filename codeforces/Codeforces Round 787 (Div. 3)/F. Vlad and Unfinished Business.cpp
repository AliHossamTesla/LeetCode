// Problem: F. Vlad and Unfinished Business
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 5:58pm 24/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t ;
	cin >> t ;
	while(t --){
		int n , k ;
		cin >> n >> k ;
		int x , y ;
		cin >> x >> y ;
		vector<int>things(k) ;
		things.push_back(y) ;
		for(int i = 0 ; i < k ; i ++)
			cin >> things[i] ;
		vector<int>adj[n + 1] ;
		for(int i = 0 ; i < n - 1 ; i ++){
			int u , v ;
			cin >> u >> v ;
			adj[u].push_back(v) ; adj[v].push_back(u) ;
		}
		vector<int>parents(n + 1,-1),dep(n + 1,0) ;
		function<void(int)> dfs = [&](int u) -> void {
			for (auto v : adj[u]) {
				if (v == parents[u]) {
					continue;
				}
				parents[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
			}
		};
		dfs(x) ;
		int ans = 0 ;
		vector<int>vis(n + 1,0) ;
		vis[x] = 1 ;
		for(auto u : things){
			while(!vis[u]){
				vis[u] = 1 ;
				ans += 2 ;
				u = parents[u] ;
			}
		}
		ans -= dep[y] ;
		cout << ans << endl ;
	}
}
/*
 * here you need to combine between greedy and graph : you go from every targets to x and if you
 * reach to visited node before you don't need to continue get idea from : https://codeforces.com/contest/1675/submission/155948486
 */