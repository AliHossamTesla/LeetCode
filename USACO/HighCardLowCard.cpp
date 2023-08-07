// Problem: Problem 1. High Card Low Card (Gold)
// Contest: USACO - USACO 2015 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=573
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
int number_of_wins( vector<ll>&A , vector<ll>& B,function <bool(ll,ll)>cmp){
	int n = A.size() ;
	assert(A.size() == B.size()) ;
	sort(all(A),cmp) ; sort(all(B),cmp) ;
	int wins = 0 ;
	for(int i = 0 , j = 0 ; i < n ; i ++){
		if(cmp(A[j],B[i])){
			wins ++ ;
			j ++ ;
		}
	}
	return wins ;
}
void doYourJop()
{
	cin >> n ;
	bool tk[2*n + 1] = {0} ;
	vector<ll>A1,A2,B1,B2 ;
	for(int i = 1 ; i <= n ; i ++){
		int val ; cin >> val ;
		tk[val] = 1 ;
		if(i <= n/2)
			A1.pb(val) ;
		else 
			A2.pb(val) ;
	}
	vector<ll>v ;
	for(int i = 1 ; i <= 2*n ; i ++)
		if(!tk[i])
			v.pb(i) ;
	sort(all(v)) ;
	ll ans = 0 ;
	for(int i = 0 ; i < n ; i ++){
		if(i < n/2)
			B1.pb(v[i]) ;
		else
			B2.pb(v[i]) ;
			
	}
	ans += number_of_wins(B2,A1,[](ll a, ll b) { return a > b; });
	ans += number_of_wins(B1,A2,[](ll a, ll b) { return a < b; });
	cout << ans << el ;
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
    setIO("cardgame") ;
    // testCase
    doYourJop();
    return 0;
}