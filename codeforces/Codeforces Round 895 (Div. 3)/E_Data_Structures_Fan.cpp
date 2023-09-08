/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0; i < N ; i++)
            cin >> A[i] ; 
        string s ; cin >> s ;
        vector<int>prefXor(N + 1,0) ;
        for(int i = 1 ; i <= N ; i++)
            prefXor[i] = prefXor[i - 1] ^ A[i - 1] ;
        int zeroVal = 0 ;
        for(int i = 0 ; i < N ; i++) zeroVal ^= (s[i] == '0' ? A[i] : 0) ;
        int Q ; cin >> Q ;
        while(Q--){
            int selector ; cin >> selector ;
            if(selector == 1){
                int l , r ; cin >> l >> r ; l -- ;
                zeroVal ^= prefXor[l] ^ prefXor[r];
            }else{
                int val ; cin >> val ;
                cout << (val ? zeroVal ^ prefXor[N] : zeroVal) << " " ;
            }
        }
        cout << endl ;
    }
}
