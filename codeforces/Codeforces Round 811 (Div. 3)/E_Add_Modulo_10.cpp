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
        bool ok = 0 ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] , ok |= (A[i]%10 == 0 or A[i] % 10 == 5) ;
        if(ok){
            for(int i = 0 ; i < N ; i ++)
                if(A[i]%10 == 5) A[i] += 5 ;
            bool bad = 0 ;
            for(int i = 0 ; i < N - 1 ; i ++)
                if(A[i] != A[i + 1]) bad = 1 ;
            cout << (bad ? "NO\n" : "YES\n") ;
        }else{
            for(int i = 0 ; i < N ; i ++){
                if(A[i] % 10 == 2) continue;
                while(A[i] % 10 != 2) A[i] += (A[i] % 10) ;
            }
            bool ok1 = 1 ;
            for(int i = 1 ; i < N ; i ++){
                int rem = abs(A[i] - A[i - 1]) % 20 ;
                ok1 &= (rem == 0 or rem == 2 or rem == 6 or rem == 14) ;
            }
            cout << (ok1 ?"YES\n":"NO\n") ;
        }
    }
}
