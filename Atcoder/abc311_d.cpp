// Problem: D - Grid Ice Floor
// Contest: AtCoder - Toyota Programming Contest 2023#4（AtCoder Beginner Contest 311）
// URL: https://atcoder.jp/contests/abc311/tasks/abc311_d
// Memory Limit: 1024 MB
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
char grid[205][205] ;
bool vis[205][205],se[205][205];
ll ans = 0 ;
void doYourJop()
{
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
			cin >> grid[i][j] ;
		clr(vis[i],0) ;
		clr(se[i],0) ;
	}
	queue<pair<int,int>>Q ;
	Q.push({1,1}) ;
	se[1][1] = vis[1][1] = 1 ;
	while(!Q.empty()){
		pair<int,int>st = Q.front() ;
		Q.pop() ;
		for(int i = 0 ; i < 4 ; i ++){
			int u = st.f , v = st.s ;
			while(grid[u + dx[i]][v + dy[i]] != '#')
			{
				u += dx[i] ;
				v += dy[i] ;
				vis[u][v] = 1 ;
			}
			if(!se[u][v]){
				se[u][v] = 1 ;
				Q.push({u,v}) ;
			}
		} 
	}
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
			if(vis[i][j])
				ans ++ ;
	}
	cout << ans << el ;
	
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}