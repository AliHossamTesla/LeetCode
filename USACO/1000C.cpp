// Problem: C. Covered Points Count
// Contest: Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1000/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	cin >> n ;
	vector<pair<ll,ll>>coor(n) ;
	set<ll>points ;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> coor[i].f >> coor[i].s ;
		points.insert(coor[i].f) ;
		points.insert(coor[i].s + 1) ;
	}
	map<ll,ll>ma ;
	vector<ll>v;
	int cr = 0 ;
	for(auto u : points)
	{
		ma[u] = cr ;
		v.push_back(u) ;
		cr ++ ; 
	}
	vector<ll>freQ(2*n,0) ;
	for(int i = 0 ; i < n ; i ++)
	{
		freQ[ma[coor[i].f]] ++ ;
		freQ[ma[coor[i].s + 1]] -- ;
	}
	for(int i = 1 ; i < 2*n ; i ++)
		freQ[i] += freQ[i - 1];
	
	vector<ll>ans(n + 1,0) ;
	for(int i = 1 ; i < (int)v.size() ; i ++)
	{
		ans[freQ[i - 1]] += v[i] - v[i - 1] ;
	}
	for(int i = 1 ; i <= n ; i ++)
		cout << ans[i] << I(i,n) ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}
/*
Due to the large constraints on l_i and r_i, it is impossible to brute force
the number of intersecting segments for each point on the coordinate line.
However, notice that we can compress the coordinates and "pretend" as if the
coordinates were between 1 and n.

This allows us to apply prefix sums on each point in our compressed number line
and retransform these compressed coordinates to the original endpoints l_i and
r_i. To compress the coordinates, we can either sort the coordinates or use an
ordered map.
*/