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
        vector<int>A(N) ;
        for(int i = 0; i < N ; i ++)
            cin >> A[i] ;
        map<int,int>mp ;int i ;
        for(i = N - 1 ; i >= 0 ; i --){
            if(mp[A[i]]) break ;
            mp[A[i]] = 1 ;
        }
        cout << (i + 1) << endl ;
    }
}
