// Problem: C. Ice Cave
// Contest: Codeforces - Codeforces Round 301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
char grid[505][505] ;
vector<vector<bool>>vis ;
int x11 , x2 , y11 , y2 ;
bool valid(int r,int c){
    if(r<0||c<0||r>=n||c>=m)return 0;
    return 1;
}
void dfs(int r , int c)
{
	if(r < 0 or r >= n or c < 0 or c >= m or grid[r][c] == 'X' or vis[r][c])
		return ;
	vis[r][c] = 1 ;
	for(int i = 0 ; i < 4 ; i ++)
		dfs(r+dx[i],c+dy[i]) ;
}
void doYourJop()
{
	cin >> n >> m ;
	vis = vector<vector<bool>>(n,vector<bool>(m,0)) ;
	for(int i = 0 ;i < n ; i ++)
		for(int j = 0 ; j < m ; j ++)
			cin >> grid[i][j] ;
	cin >> x11 >> y11 >> x2 >> y2 ;
	x11 -- ;y11 -- ;x2 -- ;y2 -- ;
	if(x11 == x2 and y11 == y2)
	{
		int cnt = 0 ;
		for(int i = 0 ; i < 4 ; i ++)
			if(valid(x2+dx[i],y2+dy[i]) and grid[x2+dx[i]][y2+dy[i]] == '.')
				cnt ++ ;
		if(cnt)
			cout << "YES\n" ;
		else
			cout << "NO\n" ;
	}else if(grid[x2][y2] == 'X')
	{
		grid[x11][y11] = '.' ;
		grid[x2][y2] = '.' ;
		dfs(x11,y11) ;
		if(vis[x2][y2])
			cout << "YES\n" ;
		else
			cout << "NO\n" ;
	}else{
		grid[x11][y11] = '.' ;
		dfs(x11,y11) ;
		if(!vis[x2][y2])
			return void(cout << "NO\n" ) ;
		int cnt = 0 ;
		for(int i = 0 ; i < 4 ; i ++)
			if(valid(x2+dx[i],y2+dy[i]) and grid[x2+dx[i]][y2+dy[i]] == '.')
				cnt ++ ;
		if(cnt >= 2)
			cout << "YES\n" ;
		else
			cout << "NO\n" ;
	}
}
int main()
{
    Ali_Hossam
    // testCase
        doYourJop();
    return 0;
}