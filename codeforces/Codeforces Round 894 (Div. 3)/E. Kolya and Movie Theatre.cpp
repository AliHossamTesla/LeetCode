// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N , M , d ;
		cin >> N >> M >> d ;
		vector<int>v(N) ;
		for(int i = 0 ;i < N ; i ++)
			cin >> v[i] ;
		int sm = 0 ,ans = 0 ;
		set<pair<int,int>>st ;
		for(int i = 0 ; i < N ; i ++){
			int cr = sm + v[i] - d*(i + 1) ;
			ans = max(ans,cr) ;
			if(v[i] > 0) {
				sm += v[i] ;
				st.insert({v[i],i}) ;
				if(st.size() >= M){
					sm -= (st.begin()->first) ;
					st.erase(st.begin()) ;
				}
			}
		}
		cout << ans << endl ;
	}
}
