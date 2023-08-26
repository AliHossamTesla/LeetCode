// Problem: D. Vertical Paths
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/D
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
ll n, k, m;
const int N = 2e5 + 5 ;
vector<bool>vis ;
int succ[N] ;
bool leaf[N] ;
int root ;
void dfs(int u,vector<int>&pth){
	if(vis[u] or u == root){
		if(u == root and !vis[u])
			vis[u] = 1, pth.pb(u) ;
		cout <<(int)pth.size() << el ;
		reverse(all(pth)) ;
		for(int i : pth)
			cout << i << sp ;
		cout << el ;
		return ;
	}
	pth.pb(u) ;
	vis[u] = 1 ;
	dfs(succ[u],pth) ;
}
void doYourJop()
{
	cin >> n ;
	vis = vector<bool>(n + 1,0) ;
	clr(leaf,1) ;
	for(int v = 1 ; v <= n ; v ++){
		int u ; cin >> u ;
		if(u == v){
			root = u ;
			continue ;
		}
		leaf[u] = 0 ;
		succ[v] = u ;
	}
	if(n ==1 ){
		cout << 1 << el << 1 << el << 1 << el ;
		cout << el ;
		return ;
	}
	int cnt = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		if(leaf[i])
			cnt ++ ;
	cout << cnt << el ;
	for(int i = 1 ; i <= n ; i ++){
		if(leaf[i]){
			vector<int>pth ;
			dfs(i,pth) ;
		}
	}
	cout << el ;
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