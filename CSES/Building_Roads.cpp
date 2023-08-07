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
ll n, k, m;
ll i, j, i1; // for iterations
vector<vector<int>>adj ;
vector<bool>vis;
void dfs(int u)
{
    if(vis[u])
        return ;
    vis[u] = 1 ;
    for(auto I : adj[u])
    {
        if(vis[I])
            continue ;
        dfs(I) ;
    }
}
void doYourJop()
{
    cin >> n >> m ;
    adj.resize(n + 1) ;
    vis.resize(n + 1) ;
    for(int i = 0 ; i < m ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>ans ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(vis[i])
            continue;
        dfs(i) ;
        ans.push_back(i) ;
    }
    cout << ans.size() - 1 << el;
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << sp << ans[i + 1] << el;
}
int main()
{
    Ali_Hossam
    // testCase
    doYourJop();
    return 0;
}
/*
    .... BFS....
    cin >> n >> m ;
    vector<int>adj[n] ;
    bool vis[n] = {0};
    queue<int>q ;
    for(int i = 0 ; i < m ; i ++)
    {
        int x , y ;
        cin >> x >> y ;
        x -- ;
        y -- ;
        adj[x].push_back(y) ;
        adj[y].push_back(x);
    }
    vector<int>ans ;
    for(int i = 0 ; i < n ; i ++)
    {
        if(vis[i])
            continue ;
        vis[i] = 1 ;
        q.push(i);
        while(!q.empty())
        {
            int s = q.front() ; q.pop() ;
            for(auto u : adj[s])
            {
                if(vis[u])
                    continue ;
                vis[u] = 1 ;
                q.push(u) ;
            }
        }
        ans.push_back(i) ;
    }
    cout << ans.size() - 1 << el ;
    for(int i = 0 ; i < ans.size() - 1 ; i ++)
        cout << ans[i] + 1 << sp << ans[i + 1] + 1 << el ;
*/