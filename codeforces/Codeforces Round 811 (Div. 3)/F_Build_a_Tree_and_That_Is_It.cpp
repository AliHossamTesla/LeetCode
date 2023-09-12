/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , d12 , d23 , d31 ;
        cin >> N >> d12 >> d23 >> d31 ;
        if ((d23 + d31 - d12)&1){
            cout << "NO\n";
            continue ;
        }
        int z = (d23 + d31 - d12) / 2;
        int x = d31 - z, y = d12 - x;
        if (z < 0 or x < 0 or y < 0){
            cout << "NO\n";
            continue;
        }
        int rod = 4 ;
        if(x == 0) rod = 1 ;
        else if(y == 0) rod = 2 ;
        else if(z == 0) rod = 3 ;
        int u = 4 + (rod == 4) ;
        if(max(x - 1,0LL) + max(y - 1,0LL) + max(z - 1,0LL) > N - u + 1){
            cout << "NO\n";
            continue;
        }
        int crX = rod , crY = rod , crZ = rod ;
        vector<int>adj[N + 1] ;
        for(int i = 1 ; i < x ; i ++)
            adj[crX].push_back(u) ,crX = u ++;
        if(rod != 1) adj[crX].push_back(1);
        for(int i = 1 ; i < y ; i ++)
            adj[crY].push_back(u) , crY = u ++;
        if(rod != 2) adj[crY].push_back(2);
        for(int i = 1 ; i < z ; i ++)
            adj[crZ].push_back(u) , crZ = u ++;
        if(rod != 3) adj[crZ].push_back(3) ;
        cout << "YES\n";
        for(;u <= N ;u ++) adj[3].push_back(u) ;
        for(int i = 1 ; i <= N ; i ++)
            for(int &I : adj[i])
                cout << i << " " << I << "\n";
    }
}
