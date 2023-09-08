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
        vector<int>ans[N + 1] ;
        for(int i = 1 ; i <= N ; i ++) ans[i].push_back(i) ;
        vector<int>adj[N + 1] ;
        for (int i = 0; i < N; i++){
            for(int j = 0 ; j < N ; j ++){
                char c ; cin >> c ;
                if(c == '1')
                    adj[i + 1].push_back(j + 1);
            }
        }
        for(int i = 1 ; i <= N ; i ++){
            for(int u : adj[i])
                ans[u].push_back(i) ;
        }
        for(int i =1  ; i <= N ; i ++){
            sort(ans[i].begin(), ans[i].end());
            cout << ans[i].size() << " " ;
            for(int &j : ans[i])
                cout << j << " " ;
            cout << endl;
        }
    }
}
