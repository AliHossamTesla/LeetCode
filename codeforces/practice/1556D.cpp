// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/D
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
int KalfYaSedy(string s, int a , int b)
{
	cout << s << sp << a << sp << b << el ;
	cout.flush() ;
	int ans ;
	return ans ;
}
int Atbo5yYaHaneem(int a ,int b)
{
	int ad = KalfYaSedy("and",a,b) ;
	int Or = KalfYaSedy("or",a,b) ;
	int xr = ~ad & Or ;
	return 2 * ad + xr ;
}
void doYourJop()
{
	cin >> n >> m ;
	vector<int>v;
	int ab = Atbo5yYaHaneem(1,2) ;
	int bc = Atbo5yYaHaneem(2,3) ;
	int ac = Atbo5yYaHaneem(1,3) ;
	v.pb((ab + ac - bc)/2) ;
	v.pb(ab - v.back()) ;
	v.pb(bc - v.back()) ;
	for(int i = 4 ; i <= n ; i ++)
		v.pb(Atbo5yYaHaneem(i - 1,i) - v.back()) ;
	sort(all(v)) ;
	cout << v[m - 1] << el ;
	cout.flush() ;
	
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}