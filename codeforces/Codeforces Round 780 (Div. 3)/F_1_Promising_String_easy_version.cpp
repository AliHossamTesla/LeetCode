#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        string s ; cin >> s ;
        int ans = 0 ;
        for(int i = 0 ; i < N ; i ++){
            int neg = 0 , pos = 0 , negCons = 0 ;
            for(int j = i ; j < N ; j ++){
                if(s[j] == '+') pos ++ ;
                if(s[j] == '-') neg ++ ;
                if(neg >= pos and (neg - pos)%3 == 0) ans ++ ;
            }
        }
        cout << ans << endl ;
    }
}
