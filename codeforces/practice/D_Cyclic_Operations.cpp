/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--){
        int N, K;
        cin >> N >> K;
        bool ok = 1;
        if (K == 1){
            for (int i = 1; i <= N; i++){
                int u;
                cin >> u;
                if (u != i) ok = 0 ;
            }
            cout << (ok ? "YES\n" : "NO\n");
            continue;
        }
        vector<int> to(N + 1, 0);
        for (int i = 1; i <= N; i++){
            int u;
            cin >> u;
            if (u == 0) continue;
            if (u == i) ok = 0 ;
            to[i] = u;
        }
        if (!ok){
            cout << "NO\n";
            continue;
        }
        vector<int>vis(N + 1,-1) ;
        for (int i = 1; i <= N; i++){
            int j = i ;
            while(vis[j] == -1){
                vis[j] = i ;
                j = to[j] ;
            }
            if(vis[j] == i){
                int cntC = 0 ;
                int cr = j ;
                do{
                    cntC ++ ;
                    cr = to[cr] ;
                }while(cr != j) ;
                if(cntC != K){
                    ok = 0 ;
                    break ;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}