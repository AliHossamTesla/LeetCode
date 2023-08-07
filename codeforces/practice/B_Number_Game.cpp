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
#define imin INT_MIN
#define f first
#define s second
#define endstr string::npos
#define imax INT_MAX
const ll oo = 2e9;
const int biti = 32;
const int bitl = 64;
const ll N = 1'000'000'000'000L;
const ll sz = 2e5 + 5;
#define Num_of_Digits(n) ((int)log10(n) + 1)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll n, k, m;
ll i, j, i1; // for iterations
// ll a[sz] , b[sz] ;
// ll d[sz] ,per[sz] , sef[sz] ;
ll getSeriesUp(ll x)
{
    ll l = 0, r = 2e9 + 7 ;
    ll ans;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll sum = (mid * (mid + 1)) / 2;
        if (sum == x)
        {
            ans = mid;
            break;
        }
        else if (sum < x)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}
void doYourJop()
{
    cin >> n >> m ;
    cout << getSeriesUp(n + m) << el ;
}
int main()
{
    Ali_Hossam
        testCase
        doYourJop();
    return 0;
}