// Problem: D. Not a Cheap String
// Contest: Codeforces - Codeforces Round 805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/D
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
	str s ; cin >> s ;
	cin >> n ;
	ll sm = 0 ;
	for(int i = 0 ; i < (int)s.size() ; i ++){
		sm += (s[i] - 'a' + 1) ;
	}
	if(n >= sm)
		return void(cout << s << el) ;
	str nw = s ;
	sort(rall(nw)) ;
	map<char,int>ma ;
	sm -= n ;
	for(int i = 0 ; i < (int)nw.size() ; i ++){
		ma[nw[i]] ++ ;
		sm -= (nw[i] - 'a' + 1) ;
		if(sm <= 0)
			break ;
	}
	str ans ;
	for(int i = 0 ; i < (int)s.size() ; i ++){
		if(ma.count(s[i]) != 0){
			ma[s[i]] -- ;
			if(ma[s[i]] == 0)
				ma.erase(ma.find(s[i])) ;
		}else
			ans.pb(s[i]) ;
	}
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