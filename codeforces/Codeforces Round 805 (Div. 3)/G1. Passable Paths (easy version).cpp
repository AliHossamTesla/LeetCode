// Problem: G1. Passable Paths (easy version)
// Contest: Codeforces - Codeforces Round 805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G1
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
#define testCase int testCase; cin >> testCase; while (testCase--)
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using ld = long double;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll i, j, i1; // for iterations
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
// BEFORE coding are you sure you understood the statement correctly?
// DON'T assume thing he doesn't say .
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.
vector<int>adj[200005] ;
bool vis[200005] ;
int dep[200005] ;
bool ok = 0 ;
void calcDepth(int u = 1 ,int v = -1){
	if(v > 0)
		dep[u] = dep[v] + 1 ;
	for(auto U : adj[u]){
		if(U != v)
			calcDepth(U,u) ;
	}
}
void dfs(int u,int cnt,int have[],int sz){
	vis[u] = 1;
	for(auto U : adj[u]){
		if(!vis[U]){
			dfs(U,cnt + (have[U]),have,sz) ;
		}
	}
	// cout << cnt << el ;
	if(cnt == sz)
		ok = 1 ;
}
void doYourJop()
{
	cin >> n ;
	for(int i = 0 ; i < n - 1 ;i++){
		int u , v ;
		cin >> u >> v ;
		adj[u].pb(v) ;
		adj[v].pb(u) ;
	}
	
	dep[1] = 1 ;
	calcDepth(); 
	int Q ;
	cin >> Q ;
	while(Q--){
		ok = 0 ;
		clr(vis,0) ;
		int sz ; 
		cin >> sz ;
		int have[n + 1] = {} ;
		int start = -1 ;
		for(int i = 0 ;i < sz ; i ++){
			int u ; cin >> u ;
			have[u] = 1;
			if(start == -1)
				start = u ;
			if(dep[u] > dep[start])
				start = u ;
		}
		// cout << start << el; 
		// cout << dep[3] << sp << dep[5] << el ;
		dfs(start,1,have,sz);
		if(ok)
			cout << "YES\n" ;
		else
			cout << "NO\n" ;
	}
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}