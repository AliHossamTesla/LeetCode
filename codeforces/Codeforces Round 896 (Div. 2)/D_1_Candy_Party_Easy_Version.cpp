/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    unordered_map<int,pair<int,int>>mp;
    for(int i = 0 ; i < 31 ; i ++)
        for(int j = 0 ; j < 31 ; j ++)
            if(i != j) mp[(1LL << i) - (1LL << j)] = {i,j} ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        int sum = accumulate(A.begin(),A.end(),0LL) ;
        if(sum % N){
            cout << "NO\n";
            continue;
        }
        sum /= N ;
        bool ok = 1 ;
        unordered_map<int,int>freQ;
        for(int i = 0 ; i < N ; i ++){
            if(A[i] == sum) continue ;
            int dif = A[i] - sum ;
            if(!mp.count(dif)){
                ok = 0 ;
                break ;
            }
            freQ[mp[dif].first] ++ ;
            freQ[mp[dif].second]--;
        }
        for(auto I : freQ)
            if(I.second)
                ok = 0 ;
        cout << (ok ? "YES\n" : "NO\n") ;
    }
}
