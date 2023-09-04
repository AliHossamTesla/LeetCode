// Problem: D. Two-Colored Dominoes
// Contest: Codeforces - Pinely Round 2 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1863/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 10:31PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		 int N , M ;
		 cin >> N >> M ;
		 char grid[N][M] ;
		vector<pair<int,int>>L[M],U[N] ;
		 for(int i = 0 ; i < N ; i ++)
			 for(int j = 0 ; j < M ; j ++){
				 cin >> grid[i][j] ;
				 if(grid[i][j] == 'L')
					 L[j].push_back({i,j}) ;
				 if(grid[i][j] == 'U')
					 U[i].push_back({i,j}) ;
			 }
		 bool bad = 0 ;
		 for(int i = 0 ; i < N ; i ++){
			 if(U[i].size() == 0) continue;
			 if(U[i].size()&1){
				 bad = 1 ;
				 break;
			 }
			 int j = 0 ;
			 for(; j < U[i].size() /2 ;j ++){
				 grid[U[i][j].first][U[i][j].second] = 'W' ;
				 grid[U[i][j].first + 1][U[i][j].second] = 'B' ;
			 }
			 for(;j < U[i].size() ; j ++){
				 grid[U[i][j].first][U[i][j].second] = 'B' ;
				 grid[U[i][j].first + 1][U[i][j].second] = 'W' ;
			 }
		 }
		 if(bad){
			 cout << -1 << endl ;
			 continue;
		 }
		 for(int i = 0 ; i < M ; i ++){
			 if(L[i].size() == 0) continue;
			 if(L[i].size()&1){
				 bad = 1 ;
				 break;
			 }
			 int j = 0 ;
			 for(; j < L[i].size() /2 ;j ++){
				 grid[L[i][j].first][L[i][j].second] = 'W' ;
				 grid[L[i][j].first][L[i][j].second + 1] = 'B' ;
			 }
			 for(;j < L[i].size() ; j ++){
				 grid[L[i][j].first][L[i][j].second] = 'B' ;
				 grid[L[i][j].first][L[i][j].second + 1] = 'W' ;
			 }
		 }
		 if(bad){
			 cout << -1 << endl ;
			 continue;
		 }
		 for(int i = 0 ; i < N ; i ++){
			 for(int j = 0 ; j < M ; j ++)
				 cout << grid[i][j];
			 cout << endl ;
		 }
	}
}
