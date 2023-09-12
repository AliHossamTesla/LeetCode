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
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        if(N&1){
            cout << 4 << endl ;
            cout << 1 << " " << N - 1 << endl ;
            cout << 1 << " " << N - 1 << endl;
            cout << 2 << " " << N << endl;
            cout << 2 << " " << N << endl;
        }else{
            cout << 2 << endl ;
            cout << 1 << " " << N << endl;
            cout << 1 << " " << N << endl;
        }

    }
}
