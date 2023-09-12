/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N,M ; cin >> N >> M;
        if(M == 1){
            cout << 0 << endl ;
            for(int i = 0 ; i < N ; i++)
                cout << 0 << endl ;
            continue ;
        }else{
            cout << min(N + 1,M) << endl ;
            int st = M;
            for (int i = 0; i < N; i++){
                if(st != 1){
                    st = st - 1;
                    for (int j = st; j < (st + M); j++)
                    cout << j % M << " ";
                    cout << endl ;
                }else{
                    for(int i = 1 ; i < M ; i ++) 
                        cout << i << " " ;
                    cout << 0 << endl ;
                }
            }
        }
    }
}
