// Problem: D - Snuke Maze
// Contest: AtCoder - AtCoder Beginner Contest 308
// URL: https://atcoder.jp/contests/abc308/tasks/abc308_d
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
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
char grid[505][505] ;
bool vis[505][505] ;
map<char,char>ma ;
void dfs(int r , int c , char s)
{
	if(r < 0 or r >= n or c < 0 or c >= m or grid[r][c] != s or vis[r][c])
		return ;
	vis[r][c] = 1 ;
	for(int i = 0 ; i < 4 ; i ++)
	{
		dfs(r + dx[i],c + dy[i],ma[grid[r][c]]) ;
	}
	
}
void doYourJop()
{
	ma = {{'s','n'},{'n','u'},{'u','k'},{'k','e'},{'e','s'}} ;
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			cin >> grid[i][j] ;
		}
	}
	// vis[0][0] = 1 ;
	dfs(0,0,grid[0][0]) ;
	if(vis[n - 1][m - 1])
		cout << "Yes\n" ;
	else
		cout << "No\n" ;
	//Ray7 Feeeeeeen
}
int main()
{
    Ali_Hossam
        // testCase
        doYourJop();
    return 0;
}