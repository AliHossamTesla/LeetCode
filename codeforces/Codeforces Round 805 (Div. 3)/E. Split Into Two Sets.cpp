#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
vector<bool>vis ;
map<int, vector<int>>adj ;
bool bad = 0 ;
int dfs(int u){
	vis[u] = 1 ;
	for(auto U : adj[u]){
		if(!vis[U])
			return 1 + dfs(U) ;
	}
	return 1 ;
}
void doYourJop()
{
	long long n ;
	cin >> n ;
	vis = vector<bool>(n + 1,0) ;
	adj.clear() ;
	bool flag = 0 ;
	for(int i = 0 ; i < n ; i ++){
		int u , v ;
		cin >> u >> v ;
		adj[u].pb(v) ; adj[v].pb(u) ;
		if(u == v or adj[u].size() > 2 or adj[v].size() > 2)
			flag = 1 ;
	}
	if(flag)
		return void( cout << "NO\n" ) ;
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[i]){
//			cout << dfs(i) << endl ;
			if(dfs(i)&1)
				return void( cout << "NO\n" ) ;
		}
	}
	cout << "YES\n" ;
}
int main() {
	int t ;
	cin >> t ;
	while(t--)
		doYourJop() ;
	return 0;
}
