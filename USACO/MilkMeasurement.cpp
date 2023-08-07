// Problem: Problem 2. Milk Measurement
// Contest: USACO - USACO 2017 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=763
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
#define foreach(v1) for(auto &i : v1)
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
struct Delta{
	int day , id , change ;
	bool operator<(Delta &y)
	{
		return day < y.day ;
	}
};
void doYourJop()
{
	cin >> n >> m ;
	unordered_map<int,ll>cows ;
	map<ll,ll>milk_prod{{m,n}} ;
	vector<Delta>changes(n);
	for(int i = 0 ; i < n ;i++)
		cin >> changes[i].day >> changes[i].id >> changes[i].change ,cows[changes[i].id] = m;
	sort(all(changes)) ;
	int cnt = 0 ;
	for(int i = 0 ; i < n ;i ++)
	{
		int cr = cows[changes[i].id] ;
		bool was_top = cr == milk_prod.rbegin() ->first ;
		int tmp1 = milk_prod[cr] ;
		milk_prod[cr] -- ;
		if(milk_prod[cr] == 0)
			milk_prod.erase(cr) ;
		cr += changes[i].change ;
		cows[changes[i].id] = cr ;
		milk_prod[cr] ++ ;
		int tmp2 = milk_prod[cr] ;
		bool is_top = cr == milk_prod.rbegin() ->first ;
		if(was_top)
		{
			if(is_top and tmp1 == tmp2)
				continue ;
			cnt ++ ;
		}else if(is_top)
			cnt ++ ;
	}
	cout << cnt << el ;
}
int main()
{
	// صلي علي النبي 
	setIO("measurement") ;
    doYourJop();
    return 0;
}