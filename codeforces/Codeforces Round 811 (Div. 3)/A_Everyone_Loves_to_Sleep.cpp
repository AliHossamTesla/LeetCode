/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , H , M ;
        cin >> N >> H >> M ;   
        M += H*60 ;
        vector<int>tim ;
        tim.push_back(M) ;
        for(int i = 0 ; i < N ; i++){
            int h , m ; cin >> h >> m ;
            m += h*60 ;
            tim.push_back(m) ;
        }
        sort(tim.begin(), tim.end()) ;
        int idx ;
        for(int i = 0 ; i <= N ; i++)
            if(tim[i] == M){
                idx = i ;
                break ;
            }
        if(idx != N){
            int ans = abs(tim[idx] - tim[idx + 1]);
            cout << ans / 60 << " " << ans % 60 << endl;
        }else{
            int ans = abs(tim[idx] - 24*60) + tim[0] ;
            cout  << ans / 60 << " " << ans % 60 << endl;
        }
        
    }
}
