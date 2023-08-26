// Problem: C. Flower City Fence
// Contest: Codeforces - Codeforces Round 894 (Div. 3)
// URL: https://codeforces.com/contest/1862/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>#include <bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<int>v(n) ;
		for(int i = 0 ; i < n ; i ++)
			cin >> v[i] ;
		 cout << ([&]()->bool{
			 if(v[0] != n)
				 return 0 ;
			 vector<int>cover(n,0) ;
			 for(int i = 0 ; i < n ; i ++)
				 cover[v[i] - 1] ++ ;
			 for(int i = n - 1; i > 0 ; i --)
				 cover[i - 1] += cover[i] ;
			 return cover == v ;
		 }() ? "YES\n" : "NO\n") ;
	}
}
/*
 * look for the testcase : 5 3 3 1 1
 * if i build horizontal for the first column take one from all 4 2 2 0 0 and first colom
 * become 5 go to second take every available one 3 1 1 0 0 and second become 3 again
 * 2 0 0 0 0  my new build is 5 3 3 0 0 take the reminder 5 3 3 1 1 so i can built it my soltuion is
 * simulation for this .
 */