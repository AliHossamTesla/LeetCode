// Problem: F. Sum and Product
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/contest/1857/problem/F
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
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll sqrt(ll a) {
    long long l=0,r=5000000001;
    while(r-l>1)
    {
        long long mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}
void doYourJop()
{
	cin >> n ;
	map<ll,ll>ma;
	for(int i = 0 ; i < n ; i ++){
		int val ; cin >> val ;
		ma[val] ++ ;
	}
	int Q ;
	cin >> Q ;
	while(Q --){
		ll x , y ;
		cin >> x >> y ;
		ll mom = 1LL * x * x - 4LL * y ;
		if(mom < 0){
			cout << 0 << sp ;
			continue ;
		}
		ll x1 = (x - sqrt(mom))/ 2 , x2 = (x + sqrt(mom))/ 2 ;
		if(x1 + x2 != x or x1 * x2 != y){
			cout << 0 << sp ;
			continue ;
		}
		if(x1 == x2){
			cout << (ma[x1]*(ma[x1] - 1)/2 )*1LL << sp ;
			continue ;
		}
		cout << 1LL*ma[x1]*ma[x2] << sp ;
		
	}
	cout << el ;
}
int main()
{
	// صلي علي سيدنا محمد
	Wady
	int testCase = 1 ;
	cin >> testCase ;
	while(testCase --)
		doYourJop();
	return 0;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * DON'T assume thing he doesn't say .
 * ANALYZE each idea you have thoroughly.
 */