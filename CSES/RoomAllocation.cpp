// Problem: Room Allocation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1164
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
struct customer{
	int idx , start , end ;
	bool operator<(const customer &y)
	{
		return start < y.start ;
	}
};
void doYourJop()
{
	cin >> n ;
	vector<customer>v(n) ;
	vector<ll>ans(n) ;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> v[i].start >> v[i].end ;
		v[i].idx = i ;
	}
	sort(all(v)) ;
	int room = 0 , lastRoom = 0 ;
	pq<pair<int,int>>pQ ;
	for(int i = 0 ; i < n ; i ++)
	{
		if(pQ.empty())
		{
			lastRoom ++ ;
			pQ.push(make_pair(-v[i].end,lastRoom)) ;
			ans[v[i].idx] = lastRoom ;
		}else{
			pair<int,int>mn = pQ.top() ;
			if(-mn.f < v[i].start)
			{
				pQ.pop() ;
				pQ.push(make_pair(-v[i].end,mn.s)) ;
				ans[v[i].idx] = mn.s ;
			}else{
				lastRoom ++ ;
				pQ.push(make_pair(-v[i].end , lastRoom)) ;
				ans[v[i].idx] = lastRoom ;
			}
		}
		room = max(room,int(pQ.size())) ;
	}
	cout << room << el ;
	for(int i = 0 ; i < n ; i ++)
		cout << ans[i] << " \n"[i == n - 1] ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}