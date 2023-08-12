// Problem: C. Insert Zero and Invert Prefix
// Contest: Codeforces - Codeforces Round 876 (Div. 2)
// URL: https://codeforces.com/contest/1839/problem/C
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
	cin >> n ;
	vector<int>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i] ;
	if(v[n - 1])
		return void( cout << "NO\n" ) ;
	cout << "YES\n" ;
	vector<int>ans ;
	for(int i = 0 , j = -1 ; i < n ; i ++){
		if(v[i] == 0){
			ans.pb(i - j - 1) ;
			for(int k = j + 1 ; k < i ; k ++)
				ans.pb(0) ;
			j = i ;
		}
	}
	reverse(all(ans)) ;
	for(int i = 0 ; i < n ; i ++)
		cout << ans[i] << I(i,n - 1) ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}