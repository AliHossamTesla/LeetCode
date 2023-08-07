// Problem: E. Correct Placement
// Contest: Codeforces - Codeforces Round 693 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1472/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// written by : Tesla
// in 1:26pm 23/6/2023
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
*/
#include <bits/stdc++.h>
#define Ali_Hossam ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define sp " "
#define el '\n'
#define all(n) n.begin(), n.end()
using namespace std;
#define ll long long
struct fri{
	int h , w ,id ;
};
struct my_min{
	pair<int,int>mn1 , mn2 ;
};
vector<pair<int, my_min>> createPrefMins(const vector<man>& a) {
	vector<pair<int,my_min>>prefMin ;
	my_min curMin{pair<int,int>(INT_MAX,-1),pair<int,int>(INT_MAX,-1)} ;
	for(auto x : a)
	{
		if(x.w < cur.)
	}
}
int main()
{
    Ali_Hossam
    int t ;
    cin >> t ;
    while(t--)
    {
    	int n ;
    	cin >> n ;
    	vector<fri>hor,ver ;
    	vector<pair<int,int>>a ;
    	for(int i = 0 ; i < n ; i ++)
    	{
    		int h , w ;
    		hor.push_back({h,w,i}) ;
    		ver.push_back({w,h,i}) ;
    		a.emplace_back(h,w) ;
    	}
    	sort(all(hor)) ;
    	sort(all(ver)) ;
    	
    }
    return 0;
}