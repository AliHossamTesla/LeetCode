// Problem: Problem 2. Field Day
// Contest: USACO - USACO 2023 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1327
// Memory Limit: 256 MB
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
void doYourJop()
{
	cin >> m >> n ;
	vector<int>v(n,0);
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			char c ;
			cin >> c ;
			if(c == 'G')
				v[i] |= (1 << j) ;
		}
	}
	// bool vis[n] = {0} ;
	for(int i = 0 ; i < n ; i ++)
	{
		int ans = 0 ;
		for(int j = 0 ; j < n ; j ++)
		{
			if(i == j)
				continue ;
			ans = max(ans,__builtin_popcount(v[i]^v[j])) ;
		}
		cout << ans << el ;
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