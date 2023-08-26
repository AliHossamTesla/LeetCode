// Problem: D. Ehab and another another xor problem
// Contest: Codeforces - Codeforces Round 525 (Div. 2)
// URL: https://codeforces.com/contest/1088/problem/D
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

int ask(int a,int b)
{
	cout << "? " << a << sp << b << el ;
	cout.flush() ;
	int ans ; cin >> ans ;
	return ans ;
}
void doYourJop()
{
	bool a_greater_than_b = ask(0,0) == 1 ;
	int a = 0 , b = 0 ;
	// 2^29 is a max bit to cheak in constraints ;
	for(int bit = 29 ; bit >= 0 ; bit --)
	{
		int Q1 = ask(a|(1 << bit),b) ;
		int Q2 = ask(a,b|(1<<bit)) ;
		if(Q1 != Q2)
		{
			if(Q1 == -1)
			{
				// case 1 
				a|= (1 << bit) ;
				b|= (1 << bit) ;
			}
			// case2 (do nothing) 
		}else{
			if(a_greater_than_b)
			{
				//case 3
				a|= (1 << bit) ;
			}else{
				b|= (1 << bit) ;
			}
			a_greater_than_b = Q1 == 1 ;
		}
	}
	cout << "! " << a << sp << b << el ;
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
Explanation
https://usaco.guide/problems/cf-ehab-and-another-another-xor-problem/solution#explanation
*/