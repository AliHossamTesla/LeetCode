// Problem: C. A-B Palindrome
// Contest: Codeforces - Codeforces Round 713 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1512/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 6:02Am 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int A[2] ;
		cin >> A[0] >> A[1] ;
		string s ; cin >> s ;
		int N = s.size() ;
		int l = 0 , r = N - 1 ;
		bool bad = 0 ;
		for(int i = 0 ; i < N ; i ++){
			if(s[i] == '?')
				continue;
			A[s[i] == '1'] -- ;
			if(A[s[i] == '1'] < 0)
				bad = 1 ;
		}
		if(bad){
			cout << -1 << endl ;
			continue ;
		}
		while(l < r){
			if(s[l] == '?' and s[r] == '?');
			else if(s[l] == '?'){
				s[l] = s[r] ;
				A[s[r] == '1'] -- ;
				if(A[s[r] == '1'] < 0)
					bad = 1 ;
			}else if(s[r] == '?'){
				s[r] = s[l] ;
				A[s[l] == '1'] -- ;
				if(A[s[l] == '1'] < 0)
					bad = 1 ;
			}
			l ++ , r -- ;
		}
		if(bad){
			cout << -1 << endl ;
			continue ;
		}
		for(int i = 0 ; i < N/2 ; i ++)
			if(s[i] == '?' and s[s.size() - i - 1] == '?'){
				if(A[0] >= 2)
					s[i] = s[s.size() - i - 1] = '0' , A[0] -= 2 ;
				else
					s[i] = s[s.size() - i - 1] = '1' , A[1] -= 2 ;
				if(A[0] < 0 or A[1] < 0)
					bad = 1 ;
			}
		if(bad){
			cout << -1 << endl ;
			continue ;
		}
		if((N&1) and s[s.size()/2] == '?'){
			if(A[0])
				s[s.size()/2] = '0' , A[0] -- ;
			else
				s[s.size()/2] = '1' , A[1] -- ;
			if(A[0] < 0 or A[1] < 0)
				bad = 1 ;
		}
		if(bad){
			cout << -1 << endl ;
			continue ;
		}
		for(int i = 0 ; i < N/2 ; i ++){
			if(s[i] != s[s.size() - i - 1])
				bad = 1 ;
		}
		if(bad){
			cout << -1 << endl ;
			continue ;
		}
		cout << s << endl ;
	}
}