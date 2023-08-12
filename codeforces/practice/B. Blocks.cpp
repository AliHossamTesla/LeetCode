// Problem: B. Blocks
// Contest: Codeforces - Codeforces Round 608 (Div. 2)
// URL: https://codeforces.com/contest/1271/problem/B
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
	int cntB = 0 , cntW = 0 ;
	str s ; 
	cin >> s ;
	for(int i = 0 ; i < n ; i ++)
		cntB += (s[i] == 'B') , cntW += (s[i] == 'W') ;
	if(cntB == 0 or cntW == 0)
		return void(cout << 0 << el) ;
	if(!(cntB&1)){
		vector<int>ans ;
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == 'B'){
				ans.pb(i) ;
				int j = i + 1 ;
				while(s[j] != 'B')
					ans.pb(j ++) ;
				i = j ;
			}
		}
		cout << ans.size() << el ;
		for(int i = 0 ; i < (int)ans.size() ; i ++)
			cout << ans[i] + 1 << I(i,(int)ans.size() - 1) ;
	}else if(!(cntW&1)){
		vector<int>ans ;
		for(int i = 0 ; i < n ; i ++){
			if(s[i] == 'W'){
				ans.pb(i) ;
				int j = i + 1 ;
				while(s[j] != 'W')
					ans.pb(j ++) ;
				i = j ;
			}
		}
		cout << ans.size() << el ;
		for(int i = 0 ; i < (int)ans.size() ; i ++)
			cout << ans[i] + 1 << I(i,(int)ans.size() - 1) ;
	}else{
		cout << -1 << el ;
	}
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}