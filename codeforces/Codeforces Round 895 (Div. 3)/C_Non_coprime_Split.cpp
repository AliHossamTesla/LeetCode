/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int L , R ; cin >> L >> R ;
        if(R - L >= 1){
            if(R&1 and R - 3 > 1)
                cout << 2 << " " << R - 3 << endl ;
            else if(R - 2 > 1)
                cout << 2 << " " << R - 2 << endl ;
            else cout << -1 << endl ;
        }else{
            if(R&1){
                int ans = -1 ;
                for(int i = 2 ; i * i <= R ; i ++){
                    if((R - i)%i == 0){
                        ans = i ;
                        break ;
                    }
                }
                (ans == -1 ? cout << -1 << endl : (cout << ans << " " << R - ans << endl)) ;
            }else{
                if (R - 2 > 1)
                    cout << 2 << " " << R - 2 << endl;
                else
                    cout << -1 << endl ;
            }
        }
    }
}
