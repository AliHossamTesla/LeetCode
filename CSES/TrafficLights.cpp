// Problem: Traffic Lights
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1163
// Memory Limit: 512 MB
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
	cin >> n >> m ;
	set<int>points;
	multiset<int>st ; st.insert(n) ;
	points.insert(0) ; points.insert(n) ;
	for(int i = 0 ; i < m ; i ++)
	{
		int val ; cin >> val ;
		auto it1 = points.upper_bound(val) ;
		auto it2 = it1 ;
		it1 -- ;
		st.erase(st.find(*it2 - *it1)) ;
		points.insert(val) ;
		st.insert(*it2 - val);st.insert(val - *it1) ;
		auto ans = st.end() ;
		ans -- ;
		cout << *ans << sp ;
	}
	cout << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase 
        doYourJop();
    return 0;
}