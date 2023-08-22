// Problem: G1. Magic Triples (Easy Version)
// Contest: Codeforces - Codeforces Round 867 (Div. 3)
// URL: https://codeforces.com/contest/1822/problem/G1
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define Wady ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
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
map<int,int>ma;
ll getPairs(vector<pair<int,int>>&vp,int&val,int idx = 0 , int cr = 1)
{
    if(idx == vp.size())
    {
        if(cr > 1)
            return 1ll*ma[val]*ma[val/cr]*ma[val/(cr*cr)] ;
        else 
            return 0 ;
    }
    ll res = 0 ;
    for(int i = 0 ; 2*i <= vp[idx].second ;i++)
    {
        res += getPairs(vp, val, idx + 1, cr);
        cr *= vp[idx].first ;
    }
    return res ;
}
void doYourJop()
{
    int n ;
    cin >> n;
    vector<int>v(n) ;
    ma.clear() ;
    for(int &i : v)
    {
        cin >> i ;
        ma[i] ++ ;
    }
    ll ans = 0 ;
    for(auto i : ma)
        if(i.s > 2)
            ans += (1ll * i.s * (i.s - 1) * (i.s - 2));
    sort(all(v)) ;
    for(int i = 0 ; i < n ; i++)
    {
        if(i and v[i] == v[i - 1])
            continue ;
        vector<pair<int,int>>vp ;
        int cr = v[i] ;
        for(auto &p : pr)
        {
            if(p*p > cr)
                break;
            if(cr % p)
                continue ;
            int cnt = 0 ;
            while(cr%p == 0)
            {
                cnt ++ ;
                cr /= p ;
                
            }
            vp.emplace_back(p, cnt);
        }
        if(cr > 1)
            vp.emplace_back(cr, 1);
        ans += getPairs(vp, v[i]);
    }
    cout << ans << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	pre();
	int testCase = 1 ;
	cin >> testCase ;
	while(testCase --)
		doYourJop();
	return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * DON'T assume thing he doesn't say .
 * ANALYZE each idea you have thoroughly.
 */