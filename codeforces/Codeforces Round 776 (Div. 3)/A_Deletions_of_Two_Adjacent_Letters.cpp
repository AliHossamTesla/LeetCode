/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ; 
    while(T--){
        string s ; cin >> s ;
        char c ; cin >> c ;
        vector<int>pos;
        for (int i = 0; i < s.size(); i++)
            if(s[i] == c) pos.push_back(i) ;
        if(pos.size() == 0) {
            cout << "NO\n";
            continue ;
        }
        bool ok = 0 ;
        for(int i = 0 ; i < pos.size() ; i ++)
            if(pos[i] % 2 == 0 and (s.size() - pos[i] - 1) % 2 == 0 ) ok = 1 ;
        cout << (ok ? "YES\n" : "NO\n") ;
    }
}
