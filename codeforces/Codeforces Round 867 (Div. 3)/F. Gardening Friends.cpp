// Problem: F. Gardening Friends
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define Wady ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll n, k, m;
vector<vector<int>>adj ;
int dep[200005][3];
void dfs(int u = 1 ,int v = -1,int t = 0){
	for(auto U : adj[u]){
		if(U == v)
			continue ;
		dep[U][t] = dep[u][t] + 1 ;
		dfs(U,u,t) ;
	}
}
void doYourJop()
{
	cin >> n >> k >> m ;
	adj = vector<vector<int>>(n + 1) ;
	for(int i = 1 ; i < n ; i ++){
		int u , v ;
		cin >> u >> v ;
		adj[u].pb(v) ;
		adj[v].pb(u) ;
	}
	dep[1][0] = 0 ;
	dfs() ;
	int  r = 1 ;
	for(int i = 1 ; i <= n ; i ++)
		if(dep[r][0] < dep[i][0])
			r = i ;
	dep[r][1] = 0 ;
	dfs(r,-1,1) ;
	r = 1 ;
	for(int i = 1 ; i <= n ; i ++)
		if(dep[r][1] < dep[i][1])
			r = i ;
	dep[r][2] = 0 ;
	dfs(r,-1,2) ;
	for(int i = 1 ; i <= n ; i ++)
		ckmax(dep[i][1],dep[i][2]) ;
	ll ans = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		ckmax(ans,dep[i][1]*k - dep[i][0] * m) ;
	cout << ans << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	int testCase = 1 ;
	cin >> testCase ;
	while(testCase --)
		doYourJop();
	return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * DON'T assume thing he doesn't say .
 * ANALYZE each idea you have thoroughly.
 */