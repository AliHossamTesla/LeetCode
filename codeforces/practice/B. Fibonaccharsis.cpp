// Problem: B. Fibonaccharsis
// Contest: Codeforces - Codeforces Round 887 (Div. 2)
// URL: https://codeforces.com/contest/1853/problem/B
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
	cin >> n >> k ;
	ll ans = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		int ed = n ;
		int cr = i ;
		bool valid = 1 ;
		for(int j = 0 ; j < k - 2 ; j ++){
			int x = cr ;
			cr = ed - x ;
			ed = x ;
			valid &= cr <= ed ;
			valid &= min(cr,ed) >= 0 ;
			if(!valid)
				break ;
		}
		ans += valid ;
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
/*
I spend alot of time to think in binary search as k is large ,but find that is wrong constrains 
as if i start fub with 0 and 1 the and k = 30 so k-th = 832040 so i can just loop and find suitable pair by 
brute force .
*/