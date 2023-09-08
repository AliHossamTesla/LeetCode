/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q ; cin >> Q ;
    while(Q--){
        int N , K ; cin >> N >> K ;
        string s ; cin >> s ;
        vector<char>A {'R','G','B'} ;
        int ans = K ;
        for(int type = 0 ; type < 3 ; type ++){
            int cnt = 0 ;
            for(int i = 0 ;i < K ; i ++)
                if(s[i] != A[(type + i)%3]) cnt ++ ;
            ans = min(ans,cnt);
            for(int i = K ; i < N ; i ++){
                if(s[i] != A[(type + i)%3]) cnt ++ ;
                if(s[i - K] != A[(type + (i - K))%3]) cnt-- ;
                ans = min(ans,cnt) ;
            }
        }
        cout << ans << endl ;
    }
}
