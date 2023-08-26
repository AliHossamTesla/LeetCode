// Problem: A. The Party and Sweets
// Contest: Codeforces - Codeforces Round 559 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1158/A
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
void doYourJop()
{
	cin >> n >> m ;
	vector<ll>v(n),v1(m) ;
	ll ans = 0 ;
	foreach(v)
		cin >> i , ans += i ;
	foreach(v1)
		cin >> i ;
	ans *= m ;
	sort(all(v)) ; sort(all(v1)) ;
	if(v[n - 1] > v1[0])
		return void(cout << -1 << el) ;
	for(int i = 1 ; i < m ; i ++)
		ans += (v1[i] - v[n - 1]) ;
	if(v1[0] != v[n - 1])
		ans += (v1[0] - v[n - 2]) ;
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