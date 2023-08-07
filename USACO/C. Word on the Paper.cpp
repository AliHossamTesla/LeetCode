// Problem: C. Word on the Paper
// Contest: Codeforces - Codeforces Round 886 (Div. 4)
// URL: https://codeforces.com/contest/1850/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char grid[8][8] ;
bool vis[70] ;
str ans ;
void floodfill(int i = 0 ,int j = 0){
	if(grid[i][j] == '.' or i < 0 or i >= n or j >= n or j < 0 or vis[i+j])
		return ;
	vis[i+j] = 1 ;
	ans.pb(grid[i][j]) ;
	for(int k = 0 ; k < 4 ; k ++)
		floodfill(i + dx[k],j + dy[k]) ;
}
void doYourJop()
{
	ans.clear() ;
	n = 8 ;
	clr(vis,0) ;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++)
			cin >> grid[i][j] ;
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++)
			floodfill(i,j) ;
	}
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}