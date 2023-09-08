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
        bool ok = 1 ;
        for(int i = 0 ; i < N - 2 ; i ++){
            string c ; cin >> c ;
            if(s.size() == 0) s += c ;
            else if(s.back() == c[0]) s.push_back(c[1]) ;
            else s += c ,ok = 0;
        }
        if(ok) s += "a" ;
        cout << s << endl ;
    }
}
