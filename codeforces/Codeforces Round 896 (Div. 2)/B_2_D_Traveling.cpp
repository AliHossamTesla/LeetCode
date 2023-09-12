/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , K , a ,  b ;
        cin >> N >> K >> a >> b ;
        vector<pair<int,int>>coor(N) ;
        for(int i = 0 ; i < N ; i++)
            cin >> coor[i].first >> coor[i].second ;
        pair<int,int> cr = coor[a - 1] , dis = coor[b - 1];
        int ansl = 1e18, ansr = 1e18;
        for(int i = 0 ; i < K ; i ++){
            ansl = min(ansl, abs(coor[i].first - cr.first) + abs(coor[i].second - cr.second));
            ansr = min(ansr, abs(coor[i].first - dis.first) + abs(coor[i].second - dis.second));
        }
        cout << min(ansl + ansr, abs(cr.first - dis.first) + abs(cr.second - dis.second)) << endl;
    }
}
