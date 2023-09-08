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
        vector<int>A,B ;
        for(int i = 0 ; i < N ; i ++){
            int val ; cin >> val ;
            if(val < 0)
                B.push_back(val) ;
            else
                A.push_back(val) ;
        }
        vector<int>packags ;
        sort(A.rbegin(), A.rend()) ; sort(B.begin(), B.end()) ;
        for(int i = 0 ; i < A.size() ; i+= M)
            packags.push_back(A[i]) ;
        for(int i = 0 ; i < B.size() ; i+= M)
            packags.push_back(abs(B[i])) ;
        sort(packags.begin(), packags.end()) ;
        int ans = packags.back() ;
        for(int i = 0 ; i < packags.size() - 1 ; i ++)
            ans += packags[i] * 2 ;
        cout << ans << endl ;
    }
}
