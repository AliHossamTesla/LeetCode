// Problem: D. Prefix Permutation Sums
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/D
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

void doYourJop()
{
	cin >> n ;
	vector<ll>v(n) ;
	vector<bool>vis(n + 1,0) ;
	v[0] = 0 ;
	for(int i = 1 ; i < n ; i ++)
		cin >> v[i] ;
	ll sm = (n*(n + 1))/2 ;
	if(v[n - 1] > sm)
		return void( cout << "NO\n" ) ;
	if(v[n - 1] == sm){
		ll gap = -1 ;
		for(int i = 1 ; i < n ; i ++){
			ll dif = v[i] - v[i - 1] ;
			if(dif > n || vis[dif]){
				if(gap == -1)
					gap = dif ;
				else
					return void( cout << "NO\n" ) ;
			}
			else
				vis[dif] = 1 ;
		}
		for(ll i = 1 ; i <= n ; i ++){
			if(gap - i > n)
				continue ;
			if(vis[gap - i] == 0 and vis[i] == 0)
				return void( cout << "YES\n" ) ;
		}
		cout << "NO\n" ;
	}else{
		ll tag = sm - v[n - 1] ;
		if(tag > n)
			return void( cout << "NO\n" ) ;
		for(int i = 1 ; i < n ; i ++){
			ll dif = v[i] - v[i - 1] ;
			if(dif > n)
				return void(cout << "NO\n") ;
			else if(vis[dif])
				return void(cout << "NO\n") ;
			else
				vis[dif] = 1 ;
		}
		if(vis[tag])
			return void( cout << "NO\n" ) ;
		cout << "YES\n" ;
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