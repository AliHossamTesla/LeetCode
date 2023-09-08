/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int l , r , a ;
        cin >> l >> r >> a ;
        int j = (r / a)  ;
        int ans = 0 ;
        for(int i = max(j * a,l) ; i <= r ; i ++)
            ans = max(ans,(i/a) + (i%a)) ;
        int t = max(j * a - 1, l);
        cout << max((r / a + r % a), (t / a + t % a)) << endl;
    }
}
