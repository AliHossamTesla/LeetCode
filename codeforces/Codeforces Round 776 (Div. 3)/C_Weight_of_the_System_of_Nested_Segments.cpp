/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , M ;
        cin >> N >> M ;
        vector<pair<int, pair<int, int>>> A(M);
        for(int i = 0 ; i < M ; i++)
            cin >> A[i].second.first >> A[i].second.second ,A[i].first = i + 1;
        sort(A.begin(), A.end(), [&](pair<int, pair<int, int>> &l, pair<int, pair<int, int>> &r){
            return l.second.second < r.second.second; 
        });
        vector<pair<int, int>> ans;
        int sum = 0 ;
        for(int i = 0 ; i < 2*N ; i ++)
            ans.push_back({A[i].second.first,A[i].first}) ,sum += A[i].second.second;
        sort(ans.begin(),ans.end());
        cout << sum << endl ;
        for(int i = 0 ; i < N ; i ++)
            cout << ans[i].second << " " << ans[2*N - 1 - i].second << endl ;
        cout << endl ;
    }
}
