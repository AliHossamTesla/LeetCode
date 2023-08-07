// Problem: C. To Become Max
// Contest: Codeforces - Codeforces Round 890 (Div. 2) supported by Constructor Institute
// URL: https://codeforces.com/contest/1856/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define Wady ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define testCase int testCase; cin >> testCase; while (testCase--)
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using ld = long double;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll i, j, i1; // for iterations
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
// BEFORE coding are you sure you understood the statement correctly?
// DON'T assume thing he doesn't say .
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.

void doYourJop()
{
	cin >> n >> k ;
	vector<ll>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i] ;
	auto fn = [&](ll mid){
		for(int i = 0 ; i < n - 1 ; i ++){
			ll df = 0 ;
			bool flag = 0 ;
			ll cnt = 0 ;
			for(int j = i ; j < n - 1 ; j ++){
				df += (mid - v[j] - cnt) ;
				if(mid - cnt <= v[j + 1] + 1){
					flag = 1 ;
					break ;
				}
				cnt ++ ;
			}
			if(df <= k and flag)
				return 1 ;
		}
		return 0 ;
	};
	// ll ans = 0 ;
	// for(ll i = 1e18/2 *1LL ; i >= 1 ; i/= 2 )
		// while(fn(ans + i))
			// ans += i ;
	// cout << max(ans,v[n - 1]) << el ;
	ll l = *max_element(all(v)) , r = 1e18 ;
	ll ans = v[n - 1] ;
	while(l < r){
		ll mid = l + (r - l + 1)/2 ;
		if(fn(mid))
		{
			l = mid  ;
			// ans = mid ;
		}else
			r = mid - 1 ;
	}
	cout << l << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}