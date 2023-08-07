// Problem: C1. Dual (Easy Version)
// Contest: Codeforces - Codeforces Round 889 (Div. 2)
// URL: https://codeforces.com/contest/1855/problem/C1
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
	vector<int>v(n);
	int x2 = 0 , y2 = 0 ;
	for(int i = 0 ; i < n ; i ++){
		cin >> v[i] ;
		if(v[i] > 0)
			y2 ++ ;
		else if(v[i] < 0)
			x2 ++ ;
	}
	vector<pair<int,int>>ans ;
	if(y2 > 12){
		int tag = -1 ;
		for(int i = 0 ; i < n ; i ++)
			if(v[i] > 0)
				tag = i;
		for(int i = 0 ; i < 5 ; i ++)
			ans.pb({tag,tag}) ;
		for(int i = 0 ; i < n ; i ++)
			if(v[i] < 0)
				ans.pb({i,tag}) ;
		for(int i = 0 ; i < n - 1 ; i ++)
			ans.pb({i + 1,i}) ;
	}else if(x2 > 12){
		int tag = -1 ;
		for(int i = 0 ; i < n ; i ++)
			if(v[i] < 0)
				tag = i ;
		for(int i = 0 ; i < 5 ; i ++)
			ans.pb({tag,tag}) ;
		for(int i = 0 ; i < n ; i ++)
			if(v[i] > 0)
				ans.pb({i,tag}) ;
		for(int i = n-2 ; i >= 0 ; i --)
			ans.pb({i,i + 1}) ;
	}else{
		int tag = -1 ;
		for(int i = 0 ; i < n ; i ++)
			if(tag == -1 or abs(v[i]) > abs(v[tag]))
				tag = i;
		if(v[tag] < 0){
			for(int i = 0 ; i < n ; i ++)
				if(v[i] > 0)
					ans.pb({i,tag}) ;
			for(int i = n- 2 ; i >= 0 ; i --)
				ans.pb({i,i + 1}) ;
		}else{
			for(int i = 0 ; i <  n ; i ++)
				if(v[i] < 0)
					ans.pb({i,tag}) ;
			for(int i = 0 ; i < n - 1; i ++)
				ans.pb({i + 1, i}) ;
		}
	}
	cout << ans.size() << el ;
	for(auto I : ans)
		cout << I.f + 1 << sp << I.s + 1 << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}