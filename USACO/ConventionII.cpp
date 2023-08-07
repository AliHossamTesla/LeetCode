// Problem: Problem 2. Convention II
// Contest: USACO - USACO 2018 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=859
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
void setIO(string name) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
struct Date{
	int ar , ti ;
	bool operator<(const Date&y)
	{
		if(ar == y.ar)
			return ti < y.ti ;
		return ar < y.ar ;
	}
};
void doYourJop()
{
	cin >> n ;
	vector<Date>v(n) ;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i].ar >> v[i].ti ;
	sort(all(v)) ;
	pq<pair<int,int>>Q ;
	int cr = v[0].ar + v[i].ti ;
	int ans = 0 ;
	int i = 1 ;
	// for(auto I : v)
		// cout << I.ar << sp << I.ti << el ;
	while(i < n)
	{
		// cout << v[i].ar << sp << cr << el ;
		while(v[i].ar <= cr)
			Q.push(make_pair(-1*v[i].ti,v[i].ar)), i ++ ;
		// while(!Q.empty())
		// {
			// cout << Q.top().f << sp << Q.top().s << el ;
			// Q.pop() ;
		// }
		if(Q.empty())
		{
			cr = v[i].ar + v[i].ti ;
			i ++ ;
			continue ;
		}
		ans = max(ans,cr - Q.top().s) ;
		cr += (-1*Q.top().f) ;
		Q.pop() ;
	}
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    // freopen("convention2.in", "r", stdin);
	// freopen("convention2.out", "w", stdout);
    // testCase
        doYourJop();
    return 0;
}