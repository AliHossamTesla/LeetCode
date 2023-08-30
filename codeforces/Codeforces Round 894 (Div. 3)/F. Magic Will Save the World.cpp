// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int w , f ;
		cin >> w >> f ;
		int N ; cin >> N ;
		vector<int>v(N) ;
		for(int i = 0; i < N ; i ++)
			cin >> v[i] ;
		int sum = accumulate(v.begin(),v.end(),0LL) ;
		int W , F ;
		vector<bool>dp(sum + 1,0) ;
		dp[0] = 1 ;
		for(int i = 0 ; i < N ; i ++){
			for(int sm = sum ; sm >= 0 ; sm --){
				if(dp[sm])
					dp[sm + v[i]] = 1 ;
			}
		}
		int ans = INT_MAX ;
		for(int i = 0 ; i <= sum ; i ++){
			if(dp[i]){
				int tmp = max((i + w - 1)/w,((sum - i) + f - 1)/f) ;
				ans = min(ans,tmp) ;
			}
		}
		cout << ans << endl ;
	}
}