// Problem: F1. Guess the K-th Zero (Easy version)
// Contest: Codeforces - Codeforces Round 719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.
int ask(int i){
	cout << "? " << 1 << sp << i << el ;
	cout.flush() ;
	int val ;
	cin >> val ;
	if(val == -1)
		exit(0) ;
	return val ;
}
void doYourJop()
{
	cin >> n >> m >> k ;
	int l = 1 , r = n;
	auto fn = [&](int mid){
		ll prefix = ask(mid) ;
		return (mid - prefix) >= k ;
	};
	ll ans = 0 ;
	while(l <= r){
		int mid = l + (r - l)/2 ;
		if(fn(mid)){
			r = mid - 1 ;
			ans = mid ;
		}
		else
			l = mid + 1 ;
	}
	cout <<"! "<<  ans << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	// testCase
	doYourJop();
	return 0;
}