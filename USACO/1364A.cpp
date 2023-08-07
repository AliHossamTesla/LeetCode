// Problem: A. XXXXX
// Contest: Codeforces - Codeforces Round 649 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1364/A
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
void doYourJop()
{
	cin >> n >> k ;
	int prefixSum = 0 ;
	pq<int,vector<int>,greater<int>>pQ ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i ++)
	{
		int val ;
		cin >> val ;
		prefixSum += val ;
		if(!pQ.empty())
			ans = max(ans,i - pQ.top()) ;
		if(prefixSum % k)
			pQ.push(i) ,ans = max(ans,i + 1);
	}
	cout << (ans ? ans : -1) << el ;
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
first if the prefix sum is not divide by k so it can be ans .
look to another side if the current perfix is not put there is subset in the first valid
the option is to sub it from the current we use proirity queue to find the smallest subset like this 
ex 
	   2 2 6  2
prefix 2 4 10 12
let k = 3 the first prefix is not divide by 3 and the last prefix is 
so when 12 - 2 = 10 % 3 != 0 and this is the answer .


*/