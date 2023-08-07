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
#define yes cout << "YES" << el
#define skip  \
    str skip; \
    getline(cin, skip);
#define no cout << "NO" << el
using namespace std;
#define value \
    ll val;   \
    cin >> val;
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" \
                  << "\n";
#define fixed(n) fixed << setprecision(n)
#define debug cout << "debug!" << el;
#define mod 1000000007
#define PI 3.1415926535897932384626433832795l

// STLs
#define all(n) n.begin(), n.end()
#define foreach(v1) for (auto &i : v1)
#define forn(n) for (int i = 0; i < n; i++)
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
#define imax INT_MAX
const ll oo = 2e9;
const ll N = 1'000'000'000'000L;
const ll sz = 2e5 + 5;
#define Num_of_Digits(n) ((int)log10(n) + 1)
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
// ll a[sz] , b[sz] ;
// ll d[sz] ,per[sz] , sef[sz] ;
vector<int> pr;
bitset<(int)5e4> isprime;
void pre()
{
    isprime.set();
    for (int i = 2; 1LL * i * i <= (ll)1e9; i++)
    {
        if (!isprime[i])
            continue;
        pr.push_back(i);
        for (int j = i * i; 1LL * j * j <= (ll)1e9; j += i)
        {
            isprime[j] = false;
        }
    }
}
map<int, int> ma;
ll getPairs(vector<pair<int, int>> &vp, int &val, int idx = 0, int cr = 1)
{
    if (idx == vp.size())
    {
        if (cr > 1)
            return 1ll * ma[val] * ma[val / cr] * ma[val / (cr * cr)];
        else
            return 0;
    }
    ll res = 0;
    for (int i = 0; 2 * i <= vp[idx].second; i++)
    {
        res += getPairs(vp, val, idx + 1, cr);
        cr *= vp[idx].first;
    }
    return res;
}
void doYourJop()
{
    int n;
    cin >> n;
    vector<int> v(n);
    ma.clear();
    for (int &i : v)
    {
        cin >> i;
        ma[i]++;
    }
    ll ans = 0;
    for (auto i : ma)
        if (i.s > 2)
            ans += (1ll * i.s * (i.s - 1) * (i.s - 2));
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        if (i and v[i] == v[i - 1])
            continue;
        vector<pair<int, int>> vp;
        int cr = v[i];
        for (auto &p : pr)
        {
            if (p * p > cr)
                break;
            if (cr % p)
                continue;
            int cnt = 0;
            while (cr % p == 0)
            {
                cnt++;
                cr /= p;
            }
            vp.emplace_back(p, cnt);
        }
        if (cr > 1)
            vp.emplace_back(cr, 1);
        ans += getPairs(vp, v[i]);
    }
    cout << ans << el;
}
int main()
{
    Ali_Hossam
    pre();
    testCase
    doYourJop();
    return 0;
}
// taarr - rataa