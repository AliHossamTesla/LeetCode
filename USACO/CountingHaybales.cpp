// Problem: Problem 1. Counting Haybales
// Contest: USACO - USACO 2016 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=666
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
void doYourJop()
{
	int Q ;
	cin >> n >> Q ;
	vector<ll>v(n) ;
	foreach(v)
		cin >> i ;
	sort(all(v)) ;
	while(Q--){
		int l , r ;
		cin >> l >> r ;
		cout << upper_bound(all(v),r) - lower_bound(all(v),l) << el ;
	}	
}
void setIO(string name) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// if (len(name)) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	// }
}
int main()
{
    // صلي علي سيدنا محمد
    // Wady
    // testCase
    setIO("haybales") ;
    doYourJop();
    return 0;
}