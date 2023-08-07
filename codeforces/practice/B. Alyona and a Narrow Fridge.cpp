// Problem: B. Alyona and a Narrow Fridge
// Contest: Codeforces - Codeforces Global Round 2
// URL: https://codeforces.com/contest/1119/problem/B
// Memory Limit: 256 MB
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
// BEFORE coding are you sure you understood the statement correctly?
// DON'T assume thing he doesn't say .
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.

void doYourJop()
{
	cin >> n >> m ;
	vector<ll>v(n) ;
	for(int i = 0 ;i < n ; i ++)
		cin >> v[i] ;
	auto fn = [&](int mid) -> bool{
		if(mid == 0)
			return 1 ;
		pq<int>Q(v.begin(),v.begin() + mid) ;
		int have = 2*m ;
		while(!Q.empty()){
			int cr = Q.top() ; Q.pop() ;
			if(have - 2*cr < 0)
				return 0 ;
			have -= 2*cr ;
			if(!Q.empty())
				Q.pop() ;
		}
		return 1 ;
	};
	int l = 0 , r =  n ;
	while(l < r){
		int mid = l + ((r - l + 1)/2) ;
		if(fn(mid))
			l = mid ;
		else
			r = mid - 1 ;
	}
	cout << l << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}