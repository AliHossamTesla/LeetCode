// Problem: Fair Elections
// Contest: CodeChef - JAN21
// URL: https://www.codechef.com/problems/FAIRELCT
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
	cin >> n >> m ;
	vector<ll>v1(n),v2(m) ;
	foreach(v1)
		cin >> i ;
	foreach(v2)
		cin >> i ;
	ll sm1 = accumulate(all(v1),0) ;
	ll sm2 = accumulate(all(v2),0) ;
	if(sm1 > sm2)
		return void(cout << 0 << el) ;
	sort(rall(v2)) ; sort(all(v1)) ;
	for(int i = 0 ; i < min(n,m) ; i ++){
		sm1 -= v1[i] ; sm2 -= v2[i] ;
		sm1 += v2[i] ; sm2 += v1[i] ;
		if(sm1 > sm2)
			return void(cout << i + 1 << el) ;
	}
	cout << -1 << el ; 
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}