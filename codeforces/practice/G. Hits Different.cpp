// Problem: G. Hits Different
// Contest: Codeforces - Codeforces Round 871 (Div. 4)
// URL: https://codeforces.com/contest/1829/problem/G
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
ll ans[2000007];
ll v[1500][1500] = {}, cr = 1;
void doYourJop()
{
	cin >> n ;
	cout << ans[n] << el ;
}
void init(){
	for(int i = 1 ; i < 1500 ; i ++){
		for(int j = i - 1 ; j >= 1 ; j --){
			v[j][i - j] = v[j - 1][i - j] + v[j][i - j - 1] - v[j - 1][i - j - 1] + (cr*cr) ;
			ans[cr] = v[j][i - j] ;
			cr ++ ;
		}
	}
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    init() ;
    testCase
        doYourJop();
    return 0;
}