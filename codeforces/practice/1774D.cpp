// Problem: D. Same Count One
// Contest: Codeforces - Polynomial Round 2022 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://www.codeforces.com/problemset/problem/1774/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// written by : Tesla
// in 1:26pm 23/6/2023
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#include<tuple>
// I / O
#define Ali_Hossam ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define oldIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define testCase     \
    int testCase;    \
    cin >> testCase; \
    while (testCase--)
#define sp " "
#define el '\n'
#define interactive cout.flush();
using namespace std;
#define value \
    ll val;   \
    cin >> val;
#define fixed(n) fixed << setprecision(n)
#define mod 1000000007
#define PI 3.1415926535897932384626433832795l

// STLs
#define all(n) n.begin(), n.end()
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define rall(n) n.rbegin(), n.rend()

// bitmasks
/*
Number of leading zeroes: __builtin_clz(x)
Number of trailing zeroes : __builtin_ctz(x)
Number of 1-bits: __builtin_popcount(x)
last one : __lg()
 */

// data
// ~
using ll = long long;
using ld = long double;
using str = string;
#define ull unsigned long long
#define f first
#define s second
#define endstr string::npos
const ll N = 1'000'000'000'000L;
const ll sz = 2e5 + 5;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll addMod(ll x, ll y, ll m) { return ((x % m) + (y % m)) % m; }
ll minsMod(ll x, ll y, ll m) { return ((x % m) - (y % m)) % m; }
ll prodMod(ll x, ll y, ll m) { return ((x % m) * (y % m)) % m; }
ll fastPowerMod(ll x, ll n, ll m)
{
    if (n == 0)
        return 1 % m;
    else if (n & 1)
        return prodMod(x, fastPowerMod(x, n - 1, m), m);
    else
        return fastPowerMod((x * x) % m, n / 2, m);
}
template <typename T>
void chkmin(T &x, T y)
{
    if (x > y)
        x = y;
}
template <typename T>
void chkmax(T &x, T y)
{
    if (x < y)
        x = y;
}
ll n, k, m;
ll i, j, i1; // for iterations

void doYourJop()
{
	cin >> n >> m ;
	vector<vector<int>>v(n,vector<int>(m)) ;
	vector<int>cnt(n,0) ;
	int cnt1 = 0 ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			cin >> v[i][j] ;
			cnt1 += v[i][j] ;
			cnt[i] += v[i][j] ; 
		}
	}
	if(cnt1 % n)
		return void(cout << -1 << el) ;
	cnt1 /= n ;
	vector<tuple<int,int,int>>ans ;
	vector<int>up,down;
	for(int i = 0 ; i < m ; i ++)
	{
		for(int j = 0 ; j < n ; j ++)
		{
			if(cnt[j] > cnt1 and v[j][i])
				up.push_back(j) ;
			if(cnt[j] < cnt1 and !v[j][i])
				down.push_back(j) ;
		}
		for(int j = 0 ;j < (int)min(down.size(),up.size());j ++)
		{
			++cnt[down[j]] ; --cnt[up[j]] ;
			ans.push_back(make_tuple(down[j] + 1,up[j] + 1,i + 1)) ;
		}
		up.clear(), down.clear() ;
	}
	cout << ans.size() << el ;
	for(auto i : ans)
		cout << get<0>(i) << sp << get<1>(i) << sp << get<2>(i) << el ;
	//Ray7 Feeeeeeen
}
int main()
{
    Ali_Hossam
        testCase
        doYourJop();
    return 0;
}