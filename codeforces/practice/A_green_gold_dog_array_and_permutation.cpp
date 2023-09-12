/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N),B(N);
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        iota(B.begin(),B.end(),0);
        sort(B.begin(),B.end(),[&](int i,int j){
            return A[i] < A[j] ;
        });
        vector<int>ans(N) ;
        for(int i = 0 ; i < N ; i ++)
            ans[B[i]] = N - i ;
        for(int i = 0 ; i < N ; i ++)
            cout << ans[i] << " \n"[i + 1 == N] ;
    }
}
