// Problem: E. Cardboard for Pictures
// Contest: Codeforces - Codeforces Round 886 (Div. 4)
// URL: https://codeforces.com/contest/1850/problem/E
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
	ll sm = 0 ;
	for(int i = 0 ; i < n ; i ++){
		ll val ;
		cin >> val ;
		sm += val ;
		m -=(val * val) ;
	}
	auto fn = [&](ll x){
		ll ans1 = 0 , ans2 = 0 ;
		ans1 = sm * x ; ans2 = n * x ;
		if(ans1 >= 1e18 or ans2 >= 1e18)
			return LONG_LONG_MAX ;
		return (ans1 + ans2 * x) ;
	};
	m /= 4 ;
	ll x = 0 ;
	ll z = sqrt(m/n) + 1 ; 
	for(ll i = z/2 ; i >= 1 ; i /= 2){
		while(fn(x + i) <= m)
			x += i ;
	}
	cout << x << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}