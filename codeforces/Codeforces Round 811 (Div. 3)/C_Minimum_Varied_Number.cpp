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
        if(N / 10 == 0) cout << N << endl ;
        else{
            string s ;
            for(int i = 9 ; i >= 1 ; i --){
                if(N < i) continue ;
                N -= i ;
                s.push_back(i + '0') ;
            }
            reverse(s.begin(), s.end()) ;
            cout << s << endl ;
        } 
    }
}
