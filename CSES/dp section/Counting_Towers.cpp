/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7, SZ = 1e6 + 5;
int one[SZ], two[SZ];
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    one[1] = two[1] = 1 ;
    for(int i = 2 ; i < SZ ; i++){
        one[i] = (2 * one[i - 1] + two[i - 1]) % MOD;
        two[i] = (4*two[i - 1] + one[i - 1]) % MOD;
    }
    while (T--){
        int N;
        cin >> N;
        cout << (one[N] + two[N]) % MOD << endl;
    }
}
