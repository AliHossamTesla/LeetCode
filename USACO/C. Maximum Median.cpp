// Problem: C. Maximum Median
// Contest: Codeforces - Codeforces Round 577 (Div. 2)
// URL: https://codeforces.com/contest/1201/problem/C
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
vector<int>v ;
int ans(int l ,int r,function<bool(int)>ok){
	while(l < r){
		int mid = l + (r - l + 1)/2 ;
		if(ok(mid))
			l = mid ;
		else
			r = mid - 1 ;
	}
	return l ;
}
void doYourJop()
{
	cin >> n >> k ;
	vector<int>v(n) ;
	foreach(v)
		cin >> i ;
	sort(all(v)) ;
	cout << ans(0,2e9,[&](int x){
		ll sm  = 0 ;
		for(int i = (n - 1)/2 ; i < n ; i ++){
			sm += max(0,x - v[i]) ;
		}
		return sm <= k ;
	}) << el ;
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
To get the current median, we first sort the array in ascending order.

Now, notice that to increase the current value to a value, say $x$.
All values currently greater than or equal to the median, must remain greater than or equal to the median.

For example, say we have the sorted array
$[1,1,2,3,4,4,5,5,6,8,8]$. The current median is $4$, so to increase the median to $6$, we have to increase the current median by $2$ and we also have to increase the $5$'s to $6$.

Following this idea, to increase the median to $x$, we need to increase all values in the second half of the array to some value greater than or equal to $x$.

Then, we binary search for the maximum possible median. We know that the number of operations required to raise
the median to $x$ increases monotonically as $x$ increases, so we can use binary
search. For a given median value $x$, the number of operations required to raise
the median to $x$ is

$$\sum_{i=(n+1)/2}^{n} \max(0, x - \texttt{arr}[i]).$$

If this value is less than or equal to $k$, then $x$ can be the median, so our
check function returns true. Otherwise, $x$ cannot be the median, so our check
function returns false.

*/