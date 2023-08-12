// Problem: E. Nastya and Potions
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

vector<ll>price ;
vector<ll>dp ;
vector<vector<ll>>component ;
ll mixing(int i){
	if(component[i].size() == 0)
		return price[i] ;
	if(dp[i] != -1)
		return dp[i] ;
	ll buy = 0 ;
	for(auto u : component[i])
		buy += min(price[u],mixing(u)) ;
	dp[i] = min(price[i],buy) ;
	return dp[i] ;
}
void doYourJop()
{
	cin >> n >> m ;
	dp = vector<ll>(n + 1,-1) ;
	component = vector<vector<ll>>(n + 1) ;
	price = vector<ll>(n + 1) ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> price[i] ;
	for(int i = 0 ; i < m ; i ++){
		int val ; cin >> val ;
		price[val] = 0 ;
	}
	for(int i = 1 ;i <= n ; i ++){
		cin >> k ;
		for(int j = 0 ; j < k ; j ++){
			int val ; cin >> val ;
			component[i].pb(val) ;
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		cout << mixing(i) << sp ;
	}
	cout << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}