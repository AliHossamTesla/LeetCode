// Problem: D. Districts Connection
// Contest: Codeforces - Codeforces Round 677 (Div. 3)
// URL: https://codeforces.com/contest/1433/problem/D
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
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
void doYourJop()
{
	cin >> n ;
	vector<int>col(n + 1);
	map<int,int>mp;
	int mn = INT_MAX , color ,tag1 ,tag2;
	for(int i= 1 ; i <= n ; i ++){
		cin >> col[i] ;
		++mp[col[i]] ;
	}
	for(auto I : mp){
		if(I.s < mn){
			mn = I.s ;
			color = I.f ;
		}
	}
	if(mn == n)
		return void( cout << "NO\n" ) ;
	cout << "YES\n" ;
	for(int i= 1 ; i <= n ; i ++)
		if(col[i] == color){
			tag1 = i ;
			break ;
		}
	vector<int>marcoon ;
	for(int i = 1 ; i <= n ; i ++){
		if(col[i] == color){
			if(i != tag1)
				marcoon.pb(i) ;
			continue ;
		}else{
			tag2 = i ;
			cout << tag1 << sp << i << el ;
		}
	}
	// cout << marcoon.size() << el ;
	if(marcoon.size() == 0)
		return ;
	for(int i : marcoon)
		cout << tag2 << sp << i << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	int testCase = 1 ;
	cin >> testCase ;
	while(testCase --)
		doYourJop();
	return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * DON'T assume thing he doesn't say .
 * ANALYZE each idea you have thoroughly.
 */