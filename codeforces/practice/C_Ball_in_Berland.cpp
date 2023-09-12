/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int a, b, K;
        cin >> a >> b >> K;
        map<int, int> boy, girl;
        vector<int> bo(K),gi(K);
        for(int i = 0 ; i < K ; i ++) cin >> bo[i] , boy[bo[i]] ++ ;
        for(int i = 0 ; i < K ; i ++) cin >> gi[i] , girl[gi[i]] ++ ; 
        int ans = 0;
        for (int i = 0; i < K; i++)
            ans += max(K - boy[bo[i]] - girl[gi[i]] + 1, 0LL);
        cout << ans / 2 << endl;
    }
}
