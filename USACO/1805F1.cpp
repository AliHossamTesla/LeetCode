// Problem: F1. Survival of the Weakest (easy version)
// Contest: Codeforces - Codeforces Round 862 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1805/F1
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
const int MOD = 1e9 + 7 ;
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll i, j, i1; // for iterations
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
ll addMod(ll x, ll y, ll m = 1e9 + 7) { return ((x % m) + (y % m)) % m; }
ll pw[3005] ;
void init()
{
	pw[0] = 1 ;
	for(int i = 1 ; i < n; i ++)
		pw[i] = pw[i - 1] * 2 % MOD ;
}
void doYourJop()
{
	cin >> n ;
	init() ;
	vector<ll>v(n);
	foreach(v)
		cin >> i ;
	sort(all(v)) ;
	ll ans = 0 ;
	for(int i = n - 1 ; i >= 1 ; i --)
	{
		ans = (ans + pw[i] * v[0]) % MOD ;
		for(int j = (int)v.size() - 1 ; j >= 0 ; --j)
			v[j] -= v[0] ;
		pq<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Q;
        int sz = v.size();
        for (int j = 0; j + 1 < sz; j++) {
            Q.push({v[j] + v[j + 1], j, j + 1});
        }
        vector<ll> nxt;
        while ((int)nxt.size() < sz - 1) {
            auto p = Q.top();
            Q.pop();
            nxt.push_back(get<0>(p));
            if (get<2>(p) + 1 < sz) {
                Q.push({v[get<1>(p)] + v[get<2>(p) + 1], get<1>(p), get<2>(p) + 1});
            }
        }
        v = nxt;
	}
	cout << (ans + v[0])%MOD << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
    doYourJop();
    return 0;
}