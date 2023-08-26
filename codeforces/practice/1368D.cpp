// Problem: D. AND, OR and square sum
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/D
// Memory Limit: 512 MB
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
	cin >> n ;
	vector<ll>v(n) ;
	foreach(v)
		cin >> i ;
	if(n == 1)
		return void(cout << v[0]*v[0] << el) ;
	unordered_map<int,int>ma ;
	int iter = 0 ;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < 20 ; j ++)
		{
			if(v[i]&(1 << j))
				ma[j] ++ ;
			iter = max(iter,ma[j]) ;
		}
	}
	ll ans = 0 ;
	for(int i = 0 ; i < iter ; i ++)
	{
		ll val = 0 ;
		for(int j = 0 ; j < 20 ; j ++)
		{
			if(ma[j])
			{
				ma[j] -- ;
				val |= (1 << j) ;
			}
		}
		ans += (val * val) ;
	}
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
/*
assume we have numbers 3 4 6 1 4 6
his binary represention is 
		3 : 00000011
		4 : 00000100
		6 : 00000110
		1 : 00000001
		6 : 00000110
		ma: 00000332
		we can divide this numbers to 3 numbers as max count is 3 ; 
		00000111 - 00000111 - 00000110
		so we get the maximum ;
*/