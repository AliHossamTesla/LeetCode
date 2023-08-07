// Problem: E - MEX
// Contest: AtCoder - AtCoder Beginner Contest 308
// URL: https://atcoder.jp/contests/abc308/tasks/abc308_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
int findMex(int a, int b, int c) {
    for (int i = 0; i <= 2; i++) {
        if (i != a && i != b && i != c) {
            return i;
        }
    }
    return 3; // This line should not be reached in this specific case
}
void doYourJop()
{
	cin >> n ;
	vector<ll>v(n);
	foreach(v)
		cin >> i ;
	str s ;
	cin >> s ;
	vector<ll>M , E , X ;
	for(int i = 0 ; i < n ; i ++)
	{
		if(s[i] == 'M')
			M.push_back(i) ;
		else if(s[i] == 'E')
			E.push_back(i) ;
		else if(s[i] == 'X')
			X.push_back(i) ;
	}
	int ans = 0 ;
	for(auto i : M)
	{
		int idx1 = upper_bound(all(E),i) - E.begin() ;
		if(idx1 == (int)E.size())
			break ;
		for(int j = idx1 ; j < (int)E.size() ; j ++){
			int idx2 = upper_bound(all(X),E[j]) - X.begin() ;
			if(idx2 == (int)X.size())
				break ;
			for(int k = idx2 ; k < (int)X.size(); k ++)
			{
				ans += findMex(v[i],v[E[j]],v[X[k]]) ;
			}
		}
	}
	cout << ans << el ;
	//Ray7 Feeeeeeen
}
int main()
{
    Ali_Hossam
        // testCase
        doYourJop();
    return 0;
}