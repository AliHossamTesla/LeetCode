// Problem: B. Ciel and Duel
// Contest: Codeforces - Codeforces Round 190 (Div. 1)
// URL: https://codeforces.com/contest/321/problem/B
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
struct card{
	// 1 -> ATK | 0 -> DEF
	bool type ;
	int sr ;
	
};
void doYourJop()
{
	cin >> n >> m ;
	vector<card>jiro , ciel ;
	for(int i = 0 ; i < n ; i ++){
		int stri ; str s ;
		cin >> s >> stri ;
		jiro.pb({s == "ATK",stri}) ;
	}
	for(int i = 0 ; i < m ; i ++){
		int k ;
		cin >> k ;
		ciel.pb({1,k}) ;
	}
	// first case: only hit ATK + assign weak cards with strong cards

	// sort by type and then by strength
	
	sort(all(jiro),[](const card &l,const card &r){
		if(l.type == r.type)
			return  l.sr < r.sr ;
		return l.type > r.type ;
	});
	sort(all(ciel),[](const card &l,const card &r){
		return  l.sr > r.sr ;
	});
	ll ans1 = 0 ;
	for(int i = 0 ; i < min(n,m) ; i ++){
		// break if either we're attacking DEF cards or we don't gain anything
		if(!jiro[i].type or ciel[i].sr <= jiro[i].sr)
			break ;
		ans1 += ciel[i].sr - jiro[i].sr ;
	}
	reverse(all(ciel)) ; reverse(all(jiro)) ;
	vector<bool>done(m,0) ;
	ll ans2 = 0 ;
	for(int i = 0 ; i < n ; i ++){
		bool fail = 0 ;
		for(int j = 0 ; j < m ; j ++){
			// if we haven't used j and this card can beat Jiro's card
			if(!done[j] and ((jiro[i].type and ciel[j].sr >= jiro[i].sr) or (!jiro[i].type && ciel[j].sr > jiro[i].sr))){
				done[j] = 1 ;
				if(jiro[i].type){
					ans2 += ciel[j].sr - jiro[i].sr;
				}
				fail = 1 ; 
				break ;
			}
		}
		// if we can't do any direct damage, output the first approach
		if(!fail)
			return void(cout << ans1 << el) ;
	}
	// add up all of the direct damage done
	for(int i = 0 ; i < m ; i ++){
		if(!done[i])
			ans2 += ciel[i].sr ;
	}
	cout << max(ans1,ans2) << el ;
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
Since we don't necessarily have to defeat all of Jiro's cards, there are two routes we can take:
1 - Focus on getting the maximum amount of damage without defeating all of Jiro's cards.
2 - Focus on defeating all of Jiro's cards and then deal direct damage.

We'll solve for each section independently.

In the first approach, note that since we're not looking towards defeating all of the cards,
we gain nothing from attacking Jiro's defense cards.
Thus, we'll pair up Jiro's weakest attack cards against our strongest attack cards.

In the second approach, to make sure that we don't lose any attack damage, 
we'll pair up Jiro's cards with the smallest card greater than it.

At the end, we'll return the larger quantity.

*/