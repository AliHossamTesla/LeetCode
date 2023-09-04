/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 1:26pm 23/6/2023 */
#include <bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N , X ;
	cin >> N >> X ;
	vector<int>A(N),B(N) ;
	for(int i = 0 ; i < N ; i ++)
		cin >> A[i] ;
	for(int i = 0 ; i < N ; i ++)
		cin >> B[i] ;
	vector<vector<int>>dp(N + 1,vector<int>(X + 1,0)) ;
	for(int i = 1 ; i <= N ; i ++){
		for(int j = 0 ; j <= X ; j ++){
			dp[i][j] = dp[i - 1][j] ;
			if(j - A[i - 1] >= 0)
				dp[i][j] = max(dp[i][j],dp[i - 1][j - A[i - 1]] + B[i - 1]) ;
		}
	}
	cout << dp[N][X] << endl ;
}
