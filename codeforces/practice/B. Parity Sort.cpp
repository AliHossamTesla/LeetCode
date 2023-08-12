// Problem: B. Parity Sort
// Contest: Codeforces - Codeforces Round 888 (Div. 3)
// URL: https://codeforces.com/contest/1851/problem/B
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
bool cmp(pair<int,int>&l,pair<int,int>&r){
	if(l.f < r.f){
		swap(l.s,r.s) ;
		return 1 ;
	}
	return 0;
}
void doYourJop()
{
	cin >> n ;
	vector<int>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i] ;
	vector<int>vsort(all(v)) ;
	sort(all(vsort)) ;
	for(int i = 0 ; i < n ; i ++)
		if((v[i]&1) != (vsort[i]&1))
			return void( cout << "NO\n" ) ;
	cout << "YES\n" ;
	// vector<pair<int,int>>even,odd ;
	// for(int i = 0 ;i < n ; i ++){
		// int val ; cin >> val ;
		// if(val&1)
			// odd.pb({val,i}) ;
		// else
			// even.pb({val,i}) ;
	// }
	// if(odd.size() == 0 or even.size() == 0)
		// return void( cout << "YES\n" ) ;
	// sort(all(even),cmp) ;
	// sort(all(odd),cmp) ;
	// for(auto I : even)
		// v[I.s] = I.f ;
	// for(auto I : odd)
		// v[I.s] = I.f ;
	// for(int i = 0 ; i < n - 1 ; i ++)
		// if(v[i] > v[i + 1])
			// return void( cout << "NO\n" ) ;
	// cout << "YES\n" ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}