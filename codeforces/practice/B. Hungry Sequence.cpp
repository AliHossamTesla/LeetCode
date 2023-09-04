// Problem: B. Hungry Sequence
// Contest: Codeforces - Codeforces Round 191 (Div. 2)
// URL: https://codeforces.com/contest/327/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 6:02Am 30/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
template<int SZ> struct Sieve {
	bitset<SZ> is_prime;vector<int> primes;
	Sieve() {
		is_prime.set(); is_prime[0] = is_prime[1] = 0;
		for (int i = 4; i < SZ; i += 2) is_prime[i] = 0;
		for (int i = 3; i*i < SZ; i += 2) if (is_prime[i])
				for (int j = i*i; j < SZ; j += i*2) is_prime[j] = 0;
		for(int j = 0 ; j < SZ ; j ++) if (is_prime[j]) primes.push_back(j);
	}
};
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N ; cin >> N  ;
	const int sz = 1e7 ;
	Sieve<sz>ans ;
	for(int i = 0 ; i < N ; i ++)
		cout << ans.primes[i] << " \n"[i + 1 == N] ;
}