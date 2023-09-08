/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; cin >> N ;
    vector<int>A(N),ans(N);
    for(int i = 0 ; i < N ; i ++)
        cin >> A[i] ;
    multiset<int>st ;
    for(int i = 0 ; i < N ; i ++){
        int val ; cin >> val ;
        st.insert(val) ;
    }
    for(int i = 0 ; i < N ; i ++){
        if(st.count(N - A[i]) != 0){
            ans[i] = 0 ; st.erase(st.find(N - A[i])) ;
        }else{
            auto it = st.upper_bound(N - A[i]);
            if(it != st.end()) ans[i] = (*it + A[i]) % N , st.erase(it) ;
            else ans[i] = (*st.begin() + A[i]) % N , st.erase(st.begin()) ;
        }
    }
    for(int i = 0 ; i < N ; i ++)
        cout << ans[i] << " \n"[i + 1 == N] ;
}
