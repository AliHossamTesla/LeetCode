/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while (T--){
        int N , K ; cin >> N >> K ;
        vector<int>A(N),B(K) ;
        for(int i = 0 ; i < N ; i++)
            cin >> A[i] ;
        for(int i = 0 ; i < K ; i++)
            cin >> B[i] ;
        sort(A.begin(),A.end()) ;
        int inti = N - 1 ;
        int ans = 0;
        for (int i = N - 1; i > (N - 1 - K); i--)
            ans += A[i] ;
        sort(B.rbegin(),B.rend()) ;
        for(int j = 0 ,i = 0;i < K; i ++){
            if(B[i] == 1) ans += A[inti --] ;
            else ans += A[j], j += (B[i] - 1);
        }
        cout << ans << endl;
    }
    
}
