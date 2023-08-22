// Problem: B. Maximum Rounding
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/contest/1857/problem/B
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
void doYourJop()
{
	str s ;
	cin >> s ;
	n = (int) s.size() ;
	int flag = -1 ;
	for(int i = 0 ; i < n ; i ++){
		if(s[i] <= '4'){
			flag = i ;
		}
		if(s[i] > '4')
			break ;
 	}
 	// cout << flag << el ;
	str ans ;
	bool carry = 0 ; int i;
	for(i = n - 1;i >= 0 ; i --){
		s[i] += carry ;
		carry = (s[i] >= '5') ;
		if(!carry and i <= flag){
			// cout << i << el  and s[i] != '4' ;
			break ;
		}
		ans.pb('0') ;
	}
	if(i < 0 and carry)
		ans.pb('1') ;
	for(;i >= 0 ; i --)
		ans.pb(s[i]) ;
	reverse(all(ans)) ;
	cout << ans << el ;
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