// Problem: E. Replace With the Previous, Minimize
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/E
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
template <class T> bool chkmax(T &a, T b) {return a<b ? a=b, true : false;}
void doYourJop()
{
	cin >> n >> k ;
	str s ;
	cin >> s ;
	char mn = 'a' ;
	for(int i = 0 ; i < n ; i ++){
		if(s[i] > mn){
			if(s[i] - 'a' > k){
				k -= mn - 'a' ;
				int trg = s[i] - k ;
				for(char c = s[i] ; c > trg ; c --){
					for(auto &C : s){
						if(C == c)
							C = char(c - 1) ;
					}
				}
				break ;
			}else
				chkmax(mn,s[i]) ;
		}
	}
	for(char &c : s)
		if(c <= mn)
			c = 'a' ;
	cout << s << el ;
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

/*
 * first thing we look to the max element can convert it to 'a'
 * -> note if we convert e -> a then we can convert all char less than or equal to e to a
 * but if we reach a char can't convert it to 'a' -> then we pick our operations needed to convert current
 * mn to 'a' and try to convert current char as possible and if we convert r -> l then we can convert any char
 * in range [r:l] to l .
 *
 * -> hint : why we end when find big char can't convert to 'a' as (aaaaaraaa) > (aaaaalzzz) .
 */