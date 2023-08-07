// Problem: C - GCD on Blackboard
// Contest: AtCoder - AtCoder Beginner Contest 125
// URL: https://atcoder.jp/contests/abc125/tasks/abc125_c
// Memory Limit: 1024 MB
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
ll pre[100005],sef[100005] ,v[100005];
void doYourJop()
{
	int n ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] ;
	pre[0] = 0 ; sef[n + 1] = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		pre[i] = __gcd(v[i],pre[i - 1]) ;
	for(int i = n ; i > 0 ; i --)
		sef[i] = __gcd(sef[i + 1],v[i]) ;
	ll ans = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		ans = max(ans,__gcd(pre[i - 1],sef[i + 1])) ;
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}