#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T  ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        vector<int>vis(N + 5,0) ;
        map<int,int>mp ;
        for(int i = 0; i < N; i++)
            cin >> A[i] , vis[(A[i] >= N? N + 4 : A[i])] = 1 ,mp[A[i]] ++ ;
        if(N == 1){
            cout << (A[0] ? "YES\n" : "NO\n") ;
            continue;
        }
        int MEX = N ;
        for(int i = 0 ; i < N ; i ++){
            if(!vis[i]){
                MEX = i ;
                break ;
            }
        }
        int fi = INT_MAX , sec = -1 ;
        if(MEX++ == N){
            cout << "NO\n";
            continue; 
        }
        for(int i = 0 ; i < N ; i ++)
            if(A[i] == MEX){
                fi = min(fi,i) ;
                sec = max(sec,i) ;
            }
        if(fi == INT_MAX or sec == -1){
            cout << "YES\n";
            continue ;
        }else if(fi == sec){
            cout << "YES\n";
            continue;
        }else{
            bool bad = 1 ;
            for(int i = fi ; i < sec ; i ++){
                if(A[i] < MEX){
                    mp[A[i]] -- ;
                    if(mp[A[i]] <= 0)
                        bad = 0 ;
                }
            }
            cout << (bad ? "YES\n" : "NO\n") ;
        }
    }
}
