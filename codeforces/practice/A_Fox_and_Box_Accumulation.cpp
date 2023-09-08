/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; cin >> N ;
    vector<int>A(N) ;
    for(int i = 0 ; i < N ; i ++)
        cin >> A[i] ;
    sort(A.begin(),A.end()) ;
    vector<vector<pair<int,int>>>st;
    for(int i = 0 ; i < N ; i ++){
        if(st.size() == 0) st.push_back({{A[i],1}}) ;
        else{
            bool fnd = 0 ;
            for(int j = 0 ; j < st.size() ; j ++){
                if(st[j].back().second <= A[i]){
                    st[j].push_back({A[i],st[j].back().second + 1}) ;
                    fnd = 1 ;
                    break ;
                }
            }
            if(!fnd) st.push_back({{A[i],1}}) ;
        }
    }
    cout << st.size() << endl ;
}
