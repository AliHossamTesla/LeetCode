#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        int p = 0 , l = 0 , r = 0 ;
        for(int i = 0 ,j = -1; i <= N ; i ++){
            if(i == N or A[i] == 0){
               pair<int,int>mn[2] = {make_pair(0,j + 1),make_pair(N,-1)} ;
                int sgn = 0 , pw = 0 ;
                for(int k = j + 1 ;k < i ; k ++){
                    pw += (abs(A[k]) == 2) ;
                    sgn ^= (A[k] < 0) ;
                    if(pw - mn[sgn].first > p){
                        p = pw - mn[sgn].first ;
                        l = mn[sgn].second ;
                        r = k + 1 ;
                    }
                    mn[sgn] = min(mn[sgn],make_pair(pw,k + 1)) ;
                }
                j = i ;
            }
        }
        cout << l << " " << N - r << endl ;
    }
}
