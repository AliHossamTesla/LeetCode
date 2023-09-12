/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        string s ; 
        cin >> s ;
        int cnt1 = 0 , cnt2 = 0;
        for(int i = 0 ; i < N / 2 ; i ++)
            cnt1 += (s[i] == s[N - i - 1]) , cnt2 += (s[i] != s[N - i - 1]) ;
        vector<char>ans(N+1,'0') ;
        if (N & 1){
            for(int i = cnt2 ; i <= cnt2 + 2*cnt1 + 1 ; i ++)
                ans[i] = '1' ;
        }else{
            for(int i = 0 ; i <= cnt1 ; i ++)
                ans[cnt2 + 2*i] = '1' ;
        }
        for(auto c : ans)
            cout << c ;
        cout << endl ;
    }
}
