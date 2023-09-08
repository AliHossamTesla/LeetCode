/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s ; cin >> s ;
    if(s.size() == 1){cout << 9 << endl ; return 0 ;}
    int ans = ('9' - s[s.size() - 1] + 1 + 9) ;
    for(int i = 1 ; i < s.size() - 1 ; i ++) 
        ans += ('9' - s[i]) ;
    cout << ans << endl ;
}
