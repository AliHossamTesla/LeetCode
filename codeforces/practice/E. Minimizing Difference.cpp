// Problem: E. Minimizing Difference
// Contest: Codeforces - Codeforces Round 592 (Div. 2)
// URL: https://codeforces.com/contest/1244/problem/E
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
	sort(all(v)) ;
	vector<ll>pre(n + 1,0) ;
	for(int i = 1 ; i <= n ; i ++)
		pre[i] = pre[i - 1] + v[i - 1] ;
	auto fn = [&](int mid) ->bool {
		for(int l = 0 ; l < n ; l ++){
			int idx = upper_bound(all(v),v[l] + mid) - v.begin() ;
			ll needed = (l * v[l] - pre[l]) + ((pre[n] - pre[idx]) - (n - idx)*(v[l] + mid)) ;
			if(needed <= k)
				return 1 ;
		}
		for(int r = 0 ; r < n ; r ++){
			int l = lower_bound(all(v),v[r] - mid) - v.begin();
			ll needed = (l*(v[r] - mid) - pre[l]) + ((pre[n] - pre[r]) - (n - r)*(v[r])) ;
			if(needed <= k)
				return 1 ;
		}
		return 0 ;
	};
	int l = 0 , r = v[n - 1] - v[0] ;
	if(r == 0)
		return void(cout << 0 << el ) ;
	while(l < r){
		int mid = l + (r - l)/2 ;
		if(fn(mid))
			r = mid ;
		else
			l = mid + 1 ;
			
	} 
	cout << l << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}