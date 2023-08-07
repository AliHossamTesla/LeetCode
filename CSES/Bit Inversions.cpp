// Problem: Bit Inversions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1188
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
set<int>positions ;
multiset<int>differs ;
void modify(int x)
{
	if(x == 0 or x == n)
		return ;
	auto it = positions.find(x) ;
	if(it != end(positions))
	{
		int a  = *prev(it) , b = *next(it) ;
		differs.erase(differs.find(x - a)) ;
		differs.erase(differs.find(b - x)) ;
		differs.insert(b - a) ;
		positions.erase(it) ;
	}else{
		it = positions.insert(x).first ;
		int a  = *prev(it) , b = *next(it) ;
		differs.erase(differs.find(b - a)) ;
		differs.insert(x - a) ;differs.insert(b - x) ;
	}
}
void doYourJop()
{
	str s;
	cin >> s ;
	n = s.size() ;
	positions.insert(0) ;
	positions.insert(n) ;
	for(int i = 1 ; i < n ; i ++)
		if(s[i] != s[i - 1])
			positions.insert(i) ;
	for(auto it = positions.begin() ; next(it) != positions.end() ; it ++)
		differs.insert(*next(it) - *it) ;
	int Q ;
	cin >> Q ;
	while(Q--)
	{
		int x;
		cin >> x;  
		modify(x - 1);
		modify(x);
		cout << *differs.rbegin() << " ";
	}
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
We'll use iterators extensively.

Let the bit string be $s=s_0s_1s_2\ldots,s_{n-1}$. In the set dif, we store
all indices $i$ such that $s_i\neq s_{i-1}$ (including $i=0$ and $i=n$). If the
elements of dif are $0=dif_1, then the longest length is
equal to

$$\max(dif_2-dif_1,dif_3-dif_2,\ldots,dif_k-dif_{k-1}).$$

We can store each of these differences in a multiset ret; after each
inversion, we'll need to output the maximum element of ret.

Inverting a bit at a 0-indexed position x corresponds to inserting x into
dif if it not currently present or removing x if it is, and then doing the
same with x+1. Whenever we insert or remove an element of dif, we should
update ret accordingly.


*/