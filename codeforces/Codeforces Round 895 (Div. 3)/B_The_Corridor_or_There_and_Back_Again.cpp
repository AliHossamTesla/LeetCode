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
        int ans = INT_MAX  ;
        for(int i = 0; i < N ; i++){
            int d , s ; cin >> d >> s ;
            s = (s + 1)/2 - 1 ;
            ans = min(ans,d + s) ;
        }

        cout << ans << endl ;
    }
}
