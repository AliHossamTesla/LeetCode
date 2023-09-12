/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N ; cin >> N ;
	vector<int>A(N),B(N),idxs(N + 1);
	for(int i = 0 ; i < N ; i ++)
		cin >> A[i] ,idxs[A[i]] = i;
	map<int,int>mp ;
	for(int i = 0 ; i < N ; i ++){
		cin >> B[i];
		int res = i - idxs[B[i]];
		mp[(res < 0 ? N + res : res)]++;
	}
	int ans = 1 ;
	for(auto I : mp) ans = max(ans,I.second) ;
	cout << ans << endl ;
}
