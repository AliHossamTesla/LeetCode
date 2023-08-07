// Problem: D. Apple Tree
// Contest: Codeforces - Codeforces Round 881 (Div. 3)
// URL: https://codeforces.com/contest/1843/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
const int sz = 2e5 + 5 ;
vector<vector<int>>adj ; 
vector<ll>dp;
void dfs(int u, int v = -1)
{
	if(adj[u].size() == 1 and u != 1)
		dp[u] = 1 ;
	for(auto U : adj[u])
	{
		if(U == v)
			continue ;
		dfs(U,u) ;
		dp[u] += dp[U] ;
	}
}
void doYourJop()
{
	cin >> n ;
	dp = vector<ll>(n + 1,0LL) ;
	adj = vector<vector<int>>(n + 1) ;
	for(int i = 0 ; i < n - 1; i ++)
	{
		int u , v ;
		cin >> u >> v ;
		adj[u].pb(v) ;
		adj[v].pb(u) ;
	}
	dfs(1) ;
	int Q ;
	cin >> Q ;
	while(Q--)
	{
		int u , v ;
		cin >> u >> v ;
		cout << dp[u] * dp[v] << el ;
	}
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}