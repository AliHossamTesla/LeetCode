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
        string s ;
        cin >> s ;
        int ans = (25*(s[0] - 'a')) + (s[1] - 'a' + (s[0] > s[1])) ;
        cout << ans << endl ;
    }
}