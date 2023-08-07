// Problem: B. Gardener and the Array
// Contest: Codeforces - Codeforces Round 843 (Div. 2)
// URL: https://codeforces.com/contest/1775/problem/B
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
 	vector<vector<int>>v(n) ;
	unordered_map<int,int>cnt ;
	for(int i = 0 ; i < n ; i ++){
		int k ; cin >> k ;
		for(int j = 0 ; j < k ; j ++){
			int val ; cin >> val ; 
			v[i].pb(val) ;
			cnt[val] ++ ;
		}
	}
	for(int i = 0 ; i < n ; i ++){
		bool flag = 1 ;
		for(auto I : v[i]){
			if(cnt[I] == 1){
				flag = 0 ;
				break ;
			}
		}
		if(flag)
			return void(cout << "Yes\n") ;
	}
	cout << "No\n" ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}