#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N);
        for(int i = 0 ; i < N ; i ++)
            cin >> A[i] ;
        int sum = 0 ;
        for(int i = 1 ; i < N ; i ++)
            sum += abs(A[i] - A[i-1]);
        int ans = max(abs(A[0] - A[1]), abs(A[N - 1] - A[N - 2]) ) ;
        for(int i = 1 ; i < N - 1 ; i ++)
            ans = max(ans, abs(A[i] - A[i - 1]) + abs(A[i] - A[i + 1]) - abs(A[i - 1] - A[i + 1])) ;
        cout << sum - ans << endl ;
    }
}
