/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int a , b , c ;
        cin >> a >> b >> c ;
        int dif = abs(a - b)  ;
        dif = (dif + 1) / 2 ;
        cout << (dif + c - 1) / c << endl ;
    }
}
