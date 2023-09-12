/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N , K ;cin >> N >> K ;
        vector<int>A(N),vis(N + 1,0);
        set<int>st ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i],st.insert(A[i]);
        if(st.size() > K){
            cout << -1 << endl ;
            continue ;
        }
        vector<int>ans;
        map<int,bool>mp ;
        int i ;
        for(i = 0 ; i < K and ans.size() < K;){
            if(mp[A[i]]){
                if(st.size() != 0){
                    ans.push_back(*st.begin());
                    mp[*st.begin()] = 1;
                    st.erase(st.begin());
                }else{
                    ans.push_back(ans.back()) ;
                }
            }else{
                ans.push_back(A[i]) ;
                st.erase(A[i]);
                mp[A[i]] = 1 ;
                i ++ ;
            }
        }
        for(; i < N ;){
            if(A[i] == ans[ans.size() % K]) ans.push_back(A[i ++]) ;
            else ans.push_back(ans[ans.size() % K]) ;
        }
        cout << ans.size() << endl ;
        for(int &i : ans)
            cout << i << " " ;
        cout << endl ;
    }
}
