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
        for (int i = 0; i < N; i++)
            cin >> A[i] ;
        vector<int>ans(N) ;
        for(int i = N ; i > 0 ; i --){
            int j = find(A.begin(),A.end(),i) - A.begin();
            ans[i - 1] = (j + 1) % (i) ;
            rotate(A.begin(),A.begin() + j + 1,A.begin() + i) ;  
        }
        for(int i = 0 ; i < N ; i ++) cout << ans[i] << " \n"[i + 1 == N] ;
    }
}
