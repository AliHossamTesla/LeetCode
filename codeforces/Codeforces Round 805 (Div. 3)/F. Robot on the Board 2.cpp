// Problem: F. Robot on the Board 2
// Contest: Codeforces - Codeforces Round 753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/F
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
const int N = 4e6 + 5 ;
int n, m, to[N];
bool vis[N];
int dp[N];
int get(int x, int y) {
    return (x - 1) * m + y;
}
bool inStack[N];
void dfs(int node){
	if(inStack[node]) {
        int cur = node;
        do{
            vis[cur] = true;
            cur = to[cur];
            dp[node] += 1;
        }while(cur!=node);
        do{
            dp[cur]=dp[node];
            cur = to[cur];
        }while(cur!=node);
        return;
    }
    inStack[node] = true;
    if(to[node] && !vis[to[node]]) {
        dfs(to[node]);
        if(vis[node]) {
            inStack[node] = 0;
            return;
        }
    }
    dp[node] = dp[to[node]] + 1;
    inStack[node] = false;
    vis[node] = true;
}
void doYourJop()
{
	cin >> n >> m ;
	for(int i = 1 ; i <= n*m ; i ++){
		vis[i] = 0 , dp[i] = 0 , to[i] = 0 ;
	}
	for(int i = 1 ; i <= n ; i ++){
		str s ;
		cin >> s ;
		s = "#" + s ;
		for(int j = 1 ; j <= m ; j ++){
			int x = i , y = j ;
			if(s[j] == 'L')y -= 1;
            if(s[j] == 'R')y += 1;
            if(s[j] == 'U')x -= 1;
            if(s[j] == 'D')x += 1;
            if(x > 0 && y > 0 && x <= n && y <= m) {
                to[get(i,j)] = get(x, y);
            }
		}
	}
	int ans = 1 ;
	for(int i = 1 ; i <= n*m ; i ++){
		if(!vis[i])
			dfs(i) ;
		if(dp[i] > dp[ans])
			ans = i ;
	}
	cout << (ans + m - 1) / m << ' ' << (ans - 1) % m + 1 << ' ' << dp[ans] << '\n';
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