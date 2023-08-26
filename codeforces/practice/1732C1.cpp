// Problem: C1. Sheikh (Easy version)
// Contest: Codeforces - Codeforces Round 830 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1732/C1
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
void doYourJop()
{
	int Q ;
	cin >> n >> Q ;
	vector<ll>prefixSum(n + 1,0) , prefixXor(n + 1,0) ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int val ; cin >> val ;
		prefixSum[i] = prefixSum[i - 1] + val ;
		prefixXor[i] = prefixXor[i - 1] ^ val ;
	}
	auto cost = [&](int l,int r){
		return (prefixSum[r] - prefixSum[l - 1]) - (prefixXor[r] ^ prefixXor[l - 1]) ;
	};
	/*
	Note that since the XOR of two numbers can never grow more than their sum,
	adding another number to our range cannot ever make our answer worse.
	Thus, the maximum value of f(l, r) is f(1, n).
	We've now reduced the problem to finding the minimum-length subsegment
	that achieves this maximum!
	*/
	ll best_cost = cost(1,n) ;
	while(Q--)
	{
		int L , R ;
		cin >> L >> R ;
		int lo = L, hi = R;
		// we make binary search to find last position give us our result ;
		while (lo < hi) {

			int mid = lo + (hi - lo) / 2;

			bool possible = 0;


			for (int i = 1; i + mid - 1 <= n; i++) {

				// if this segment has the most optimal cost

				if (cost(i, i + mid - 1) == best_cost) {

					possible = 1;

					break;

				}

			}


			if (possible) {

				hi = mid;

			} else {

				lo = mid + 1;

			}

		}


		for (int i = 1; i + lo - 1 <= n; i++) {

			// this was the segment we found

			if (cost(i, i + lo - 1) == best_cost) {

				cout << i << ' ' << i + lo - 1 << el;

				break;

			}

		}
	}
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    testCase
        doYourJop();
    return 0;
}
/*
From the hint, we now just have to find the minimum-length subsegment that 
achieves the maximum value of f(l, r).
Remember that since the XOR of two numbers can never grow more than their sum,
including extra elements will never make our answer worse.
Therefore, our length is actually monotonically increasing
*/