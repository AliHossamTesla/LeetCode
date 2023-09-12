/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , X; cin >> N >> X ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        sort(A.begin(), A.end());
        for(int i = 0 ; i < N ; i ++)
            A[i] = (X + A[i] - 1)/A[i] ;
        int cnt = 0 ,ans = 0 ;
        for(int i = N - 1 ; i >= 0 ; i --){
            if(A[i] <= cnt + 1) cnt = 0 , ans ++ ;
            else cnt ++ ;
        }
        cout << ans << endl;
    }
}
