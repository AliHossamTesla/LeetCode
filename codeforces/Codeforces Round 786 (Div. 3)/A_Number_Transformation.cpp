/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 1:26pm 23/6/2023 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , M ;
        cin >> N >> M ;
        if(M%N == 0)
            cout << 1 << " " << M/N << endl ;
        else
            cout << "0 0" << endl ;
    }
}
