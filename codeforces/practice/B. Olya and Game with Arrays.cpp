// Problem: B. Olya and Game with Arrays
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/contest/1859/problem/B
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
// DON'T assume thing he doesn't say .
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.

void doYourJop()
{
	cin >> n ;
	pq<int>Q;
	int mn = INT_MAX;
	for(int i = 0 ; i < n ; i ++){
		cin >> m ;
		pq<int,vector<int>,greater<int>>tmp ;
		for(int j = 0 ; j < m ; j ++){
			int val ; cin >> val ;
			tmp.push(val) ;
			mn = min(mn,val) ;
		}
		mn = min(tmp.top(),mn) ;
		tmp.pop() ;
		Q.push(tmp.top()) ;
	}
	ll ans = 0 ;
	for(int i = 1 ; i < n ; i ++){
		ans += Q.top() ;
		Q.pop();
	}
	ans += mn ;
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}