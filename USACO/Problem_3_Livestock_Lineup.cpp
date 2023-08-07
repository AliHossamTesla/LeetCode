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
vector<str> order ;
void doYourJop()
{
    ifstream read("lineup.in");
    cin >> n ;
    vector<int>adj[8] ;
    map<string, int> ma = {{"Beatrice", 0}, {"Belinda", 1}, {"Bella", 2}, {"Bessie", 3}, {"Betsy", 4}, {"Blue", 5}, {"Buttercup", 6}, {"Sue", 7}};
    map<int, string> ma1 = {{0, "Beatrice"}, {1, "Belinda"}, {2, "Bella"}, {3, "Bessie"}, {4, "Betsy"}, {5, "Blue"}, {6, "Buttercup"}, {7, "Sue"}};
    for (int i = 0; i < n; i++)
    {
        str s1, s2;
        for(int j = 0 ; j < 6 ; j ++)
        {
            str s ;
            cin >> s ;
            if(j == 0)
                s1 = s ;
            if(j == 5)
                s2 = s ;
        }
        adj[ma[s1]].push_back(ma[s2]);
        adj[ma[s2]].push_back(ma[s1]);
    }
    vector<bool>vis(8,0) ;
    ofstream out("lineup.out");
    for(int i = 0 ; i < 8 ; i++)
    {
        if (vis[i] or adj[i].size() > 1)
            continue ;
        cout << ma1[i] << el ;
        // order.push_back(ma1[i]);
        vis[i] = 1 ;
        if(adj[i].size() == 0)
            continue;
        for(auto I : adj[i])
        {
            if (vis[I])
                continue;
            cout << ma1[I] << el;
            // order.push_back(ma1[I]);
            vis[I] = 1 ;
            for (auto j : adj[I])
            {
                if (vis[j])
                    continue;
                cout << ma1[j] << el;
                // order.push_back(ma1[j]);
                vis[j] = 1;
            }
        }
    }
    // ofstream out("lineup.out");
    // for (auto c : order)
    // {
    //     out << c << endl;
    // }
}
int main()
{
    Ali_Hossam
    doYourJop();
    return 0;
}