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
        vector<int>A(N) ;
        int g1 = 0 , g2 = 0 ;
        for(int i = 0; i < N ; i++){
            cin >> A[i] ;
            if(i&1) g1 = __gcd(A[i],g1) ;
            else g2 = __gcd(A[i],g2) ;
        }
        bool bad1 = 0 , bad2 = 0 ;
        for(int i = 0; i < N ; i++){
            if(i&1 and A[i] % g2 == 0) bad1 = 1 ;
            else if(!(i&1) and A[i] % g1 == 0) bad2 = 1 ;
        }
        cout << (bad1 & bad2 ? 0 : (bad1 ? g1 : g2)) << endl;
    }
}
