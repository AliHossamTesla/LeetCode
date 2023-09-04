// Problem: C. Queries for the Array
// Contest: Codeforces - Educational Codeforces Round 154 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1861/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 8:32PM 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		string A ;
		cin >> A ;
		stack<int>st ;
		bool ok = 1 ;
		for(int i = 0 ; i < A.size() ; i ++){
			if(A[i] == '+'){
				if(st.size() < 2 or st.top() != 0)
					st.push(-1) ;
				else
					st.push(0) ;
			}else if(A[i] == '-'){
				if(st.size() <= 2 or st.top() != 1) //
					st.pop() ;
				else{
					st.pop() ; st.pop() ;
					st.push(1) ;
				}
			}else if(A[i] == '1'){
				if(st.size() <= 1) continue;
				else if(st.top() != 0){
					st.pop() ;
					st.push(1) ;
				}else{
					ok = 0 ;
					break ;
				}
			}else{
				if(st.size() < 2){
					ok = 0 ;
					break ;
				}else if(st.top() != 1){
					st.pop() ;
					st.push(0) ;
				}else{
					ok = 0 ;
					break ;
				}
			}
		}
		cout << (ok ? "YES\n" : "NO\n") ;
	}
}
