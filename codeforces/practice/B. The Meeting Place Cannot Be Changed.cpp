// Problem: B. The Meeting Place Cannot Be Changed
// Contest: Codeforces - Codeforces Round 403 (Div. 2, based on Technocup 2017 Finals)
// URL: https://codeforces.com/contest/782/problem/B
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
const double MAX_ERROR = 10e-7;
void doYourJop()
{
	cin >> n ;
	vector<pair<double,double>>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i].f ;
	for(int i = 0 ; i < n ; i++)
		cin >> v[i].s ;
	sort(all(v)) ;
	auto ok = [&](double t) -> bool {
		double met = v[n - 1].f - (t * v[n - 1].s) ;
		for(int i = n - 2 ; i >= 0 ; i --){
			if(v[i].f <= met){
				if((met - v[i].f)/v[i].s > t)
					return 0 ;
			}else{
				if(v[i].f - (t*v[i].s) > met)
					met = v[i].f - (t*v[i].s) ;
			}
		}
		return 1 ;
	};
	double l = 0 , r = 1e9 ;
	for(int i = 0 ; i < 60 ; i ++){
		double mid = (r + l)/2.0 ;
		if(ok(mid)){
			r = mid ;
		}else{
			l = mid ;
		}
	}
	// l += 1e-6 ;
	cout << fixed << setprecision(6) << l << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}