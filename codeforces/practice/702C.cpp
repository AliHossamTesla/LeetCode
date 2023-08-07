// Problem: C. Cellular Network
// Contest: Codeforces - Educational Codeforces Round 15
// URL: https://codeforces.com/contest/702/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// written by : Tesla
// in 1:26pm 23/6/2023
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
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
	vector<ll>v1(n) , v2(m) ;
	foreach(v1)
		cin  >> i ;
	foreach(v2)
		cin >> i ;
	// sort(all(v1)) ;
	// sort(all(v2)) ;
	ll r = 0 ;
	ll cr = 0 ;
	for(int i = 0 ; i < n ; i ++)
	{
		int idx = upper_bound(all(v2),v1[i]) - v2.begin() ;
		cr = abs(v2[idx] - v1[i]) ;
		if(idx == m)
			cr = abs(v2[idx - 1] - v1[i]) ;
		else if(idx != 0)
			cr = min(cr,abs(v2[idx - 1] - v1[i])) ;
		r = max(cr,r) ;
	}
	cout << r << el ;
	//Ray7 Feeeeeeen
}
int main()
{
    Ali_Hossam
        // testCase
        doYourJop();
    return 0;
}