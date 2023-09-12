/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , K ; cin >> N >> K ;
        int i = 0 , ans = 0 ;
        while(i + K <= N){
            cout << "? " << i + 1 << endl ;
            int res ; cin >> res ;
            ans ^= res ;
            i += K ;
        }
        int half = N - i ;
        half /= 2 ;
        cout << "? " << N - K - half + 1 << endl ;
        int res ; cin >> res ;
        ans ^= res ;
        cout << "? " << N - K + 1 << endl ;
        cin >> res ;
        ans ^= res ;
        cout << "! " << ans << endl ;
    }
}
