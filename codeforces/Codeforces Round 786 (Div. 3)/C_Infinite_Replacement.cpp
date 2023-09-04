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
        string A , B ; cin >> A >> B ;
        bool ok = 1 ;
        if(count(B.begin(),B.end(),'a') != 0){
            cout << (B.size() == 1 ? 1 : -1) << endl ;
            continue ;
        }
        cout << (1LL << (int)A.size()) << endl ;
    }
}
