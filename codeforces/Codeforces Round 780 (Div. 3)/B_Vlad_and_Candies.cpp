#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        if(N == 1) cout << (A[0] == 1 ? "YES\n" : "NO\n") ;
        else{
            sort(A.begin(), A.end());
            cout << (A[N - 1] - A[N - 2] <= 1 ? "YES\n" : "NO\n");
        }
    }
}
