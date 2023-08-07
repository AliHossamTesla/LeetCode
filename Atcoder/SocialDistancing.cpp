// Problem: Problem 1. Social Distancing
// Contest: USACO - USACO 2020 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1038
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
	cin >> n >> m ;
	vector<pair<ll,ll>>v(m);
	// ll l = 0 , r = 0 ;
	for(int i = 0 ; i < m ;i ++){
		cin >> v[i].f >> v[i].s ;
	}
	sort(all(v)) ;
	auto ok = [&](ll x){
		int cnt = 1 ;
		ll cr = v[0].f ;
		int i = 0 ;
		while(cr + x <= v[m - 1].s){
			while(cr <= v[i].s)
			{
				cnt ++ ;
				cr += x ;
			}
			i ++ ;
			cr = max(cr,v[i].f) ;
			// if(cnt == n)
				// break ;
		}
		return cnt >= n ;
	};
	// ll l = 0 ,r = v[m - 1].s - v[0].f + 1 ;
	// while(l < r){
		// ll mid = l + (r - l + 1)/2 ;
		// int cnt = 1 ;
		// int i = 0 ;
		// ll cr = v[i].f ;
		// while(cr + mid <= v[m - 1].s){
			// while(cr + mid > v[i].s)
				// i ++ ;
			// cr = max(cr + mid,v[i].f) ;
			// cnt ++ ;
			// if(cnt == n)
				// break ;
		// }
		// if(cnt >= n)
			// l = mid ;
		// else 
			// r = mid - 1 ;
	// }
	// cout << l << el ;
	ll l = 0 ,r = v[m - 1].s - v[0].f + 1 ;
	while(l < r){
		ll mid = l + (r - l + 1)/2 ;
		if(ok(mid))
			l = mid ;
		else 
			r = mid - 1 ;
	}
	cout << l << el ;
}
void setIO(string name) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int main()
{
    // صلي علي سيدنا محمد
    setIO("socdist") ;
    // testCase
        doYourJop();
    return 0;
}