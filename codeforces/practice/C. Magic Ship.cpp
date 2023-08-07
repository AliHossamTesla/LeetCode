// Problem: C. Magic Ship
// Contest: Codeforces - Educational Codeforces Round 60 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1117/C
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
	ll x1 , y1 , x2 , y2 ;
	cin >> x1 >> y1 >> x2 >> y2 ;
	cin >> n ;
	str s ; cin >> s ;
	auto fn = [&](ll mid){
		ll x = 0 , y = 0 ;
		for(int i = 0 ; i < s.size() ; i ++){
			if(s[i] == 'U')
				y ++ ;
			else if(s[i] == 'D')
				y -- ;
			else if(s[i] == 'L')
				x -- ;
			else 
				x ++ ;	
		}
		x *= mid / s.size() ;
		y *= mid / s.size() ;
		ll re = mid % s.size() ;
		for(int i = 0 ; i < re ; i ++){
			if(s[i] == 'U')
				y ++ ;
			else if(s[i] == 'D')
				y -- ;
			else if(s[i] == 'L')
				x -- ;
			else 
				x ++ ;	
		}
		x += x1 ; y += y1 ;
		ll dif_x = abs(x - x2) , dif_y = abs(y - y2) ;
		return (dif_x + dif_y) <= mid ;
	};
	ll l = 0 , r = INT64_MAX/2 ;
	ll ans = -1 ;
	while(l <= r){
		ll mid = l + (r - l)/2 ;
		if(fn(mid))
			ans = mid ,r = mid - 1;
		else 
			l = mid + 1 ;
	}
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}