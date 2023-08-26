// Problem: B. USB vs. PS/2
// Contest: Codeforces - Educational Codeforces Round 17
// URL: https://codeforces.com/contest/762/problem/B
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
void doYourJop()
{
	cin >> n >> m >> k ;
	int sz ; cin >> sz ;
	pq<int,vector<int>,greater<int>>Q1,Q2 ;
	for(int i = 0 ; i < sz ; i ++){
		int val ; str s ;
		cin >> val >> s ;
		if(s == "USB")
			Q1.push(val) ;
		else 
			Q2.push(val) ;
	}
	ll cnt = 0 , ans = 0 ;
	for(int i = 0 ; i < n and !Q1.empty(); i ++){
		cnt ++ ;
		ans += Q1.top() ;
		Q1.pop() ;
	}
	for(int i = 0 ; i < m and !Q2.empty(); i ++){
		cnt ++ ;
		ans += Q2.top() ;
		Q2.pop() ;
	}
	for(int i = 0 ; i < k and (!Q1.empty() or !Q2.empty()) ; i ++){
		if(Q1.empty()){
			ans += Q2.top() ;
			Q2.pop() ;
		}else if(Q2.empty()){
			ans += Q1.top() ;
			Q1.pop() ;
		}else{
			if(Q1.top() < Q2.top()){
				ans += Q1.top() ;
				Q1.pop() ;
			}else{
				ans += Q2.top() ;
				Q2.pop() ;
			}
		}
		cnt ++ ;
	}
	cout << cnt << sp << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}