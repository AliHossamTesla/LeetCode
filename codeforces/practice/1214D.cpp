// Problem: D. Treasure Island
// Contest: Codeforces - Codeforces Round 583 (Div. 1 + Div. 2, based on Olympiad of Metropolises)
// URL: https://codeforces.com/problemset/problem/1214/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
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
#define fixed(n) fixed << setprecision(n)
#define mod 1000000007
#define PI 3.1415926535897932384626433832795l
#define all(n) n.begin(), n.end()
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
/*
Number of leading zeroes: __builtin_clz(x)
Number of trailing zeroes : __builtin_ctz(x)
Number of 1-bits: __builtin_popcount(x)
last one : __lg()
 */
using ll = long long;
using ld = long double;
using str = string;
#define ull unsigned long long
#define f first
#define s second
#define endstr string::npos
const ll N = 1'000'000'000'000L;
const ll sz = 2e5 + 5;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
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
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll i, j, i1; // for iterations
vector<vector<char>>grid;
vector<vector<bool>>vis;
bool ok(int i, int j) {
	return i > 0 and i <= n and j > 0 and j <= m and not vis[i][j] and grid[i][j] == '.';
}
bool dfs(int x , int y)
{
	if(x == n and y == m)
		return 1;
	vis[x][y] = 1 ;
	if(ok(x + 1, y) and dfs(x + 1, y))
		return 1 ;
	if(ok(x , y + 1) and dfs(x,y + 1))
		return 1 ;
	return 0 ;
}
void doYourJop()
{
	cin >> n >> m ;
	grid = vector<vector<char>>(n + 1,vector<char>(m + 1)) ;
	vis = vector<vector<bool>>(n + 1,vector<bool>(m + 1,0)) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> grid[i][j] ;
		}
	}
	if(!dfs(1,1))
		cout << 0 << el ;
	else if(dfs(1,1))
		cout << 2 << el ;
	else 
		cout << 1 << el ;
}
int main()
{
    Ali_Hossam
    // testCase
        doYourJop();
    return 0;
}