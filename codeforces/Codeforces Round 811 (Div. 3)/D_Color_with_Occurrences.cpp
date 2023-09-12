/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        string t ; cin >> t ;
        int N ; cin >> N ;
        vector<string> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        vector<array<int,2>>ans ;
        bool ok = 1 ;
        function<void(int,int)> find = [&](int a,int b) ->void{
            int mx = 0 , id = -1 , pos = -1 ;
            for(int i = a ; i <= b ; i ++){
                for(int j = 0 ; j < N ; j ++){
                    string s = A[j] ;
                    if(i + s.size() > t.size() or i + s.size() <= b) continue ;
                    if(t.substr(i,s.size()) == s){
                        if(i + s.size() > mx){
                            mx = i + s.size() ;
                            id = j ;
                            pos = i ;
                        }
                    }
                }
            }
            if(id == -1){
                ok = 0 ;
                return ;
            }else{
                ans.push_back({id,pos}) ;
                if(mx == t.size()) return ;
                else find(max(pos + 1,b + 1),mx) ;
            }
        };
        find(0,0) ;
        if(!ok) cout << -1 << endl ;
        else{
            cout << ans.size() << endl ;
            for(auto I : ans)
                cout << I[0] + 1 << " " << I[1] + 1 << endl ;
        }
    }
}
