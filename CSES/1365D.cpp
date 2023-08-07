// Problem: D. Solve The Maze
// Contest: Codeforces - Codeforces Round 648 (Div. 2)
// URL: https://codeforces.com/contest/1365/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
char grid[60][60] ;
bool vis[60][60] ;
void floodfill(int r , int c )
{
	if(r < 0 or r >= n or c < 0 or c >= m or grid[r][c] == '#' or vis[r][c])
		return ;
	vis[r][c] = 1 ;
	floodfill(r,c+1) ;floodfill(r,c-1) ;
	floodfill(r+1,c) ;floodfill(r-1,c) ;
}
void doYourJop()
{
	memset(grid, '.', sizeof(grid));
	memset(vis, 0, sizeof(vis));
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			cin >> grid[i][j] ;
		}
	}
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			if(grid[i][j] == 'B')
			{
				for(int x = 0 ; x < 4 ; x ++)
				{
					int nw = i + dx[x] ;
					int mw = j + dy[x] ;
					if(nw >= 0 and nw < n and mw >= 0 and mw < m)
					{
						if(grid[nw][mw] == 'G')
							return void(cout << "No\n");
						else if(grid[nw][mw] == '.')
							grid[nw][mw] = '#' ;
					}
				}
			}
		}
	}
	floodfill(n - 1,m - 1) ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)
		{
			if(grid[i][j] == 'G' and vis[i][j] == 0)
				return void( cout << "No\n" ) ; 
		}
	}
	cout << "Yes\n" ;
	//Ray7 Feeeeeeen
}
int main()
{
    Ali_Hossam
        testCase
        doYourJop();
    return 0;
}