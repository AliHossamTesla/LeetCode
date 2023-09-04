/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 1:26pm 23/6/2023 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; 
    cin >> N ;
    vector<int>A(N) ;
    for(int i = 0; i < N ; i ++)
        cin >> A[i] ;
    int ans = INT_MAX ;
    for(int i = 0 ; i < N - 1 ; i ++){
        int cr = 0 , x = A[i] , y = A[i + 1] ;
        if(x < y) swap(x,y)  ;
        cr = min(x - y,(x + 1)/2LL) ;
        x -= 2*cr ;
        y -= cr ;
        if(x > 0 and y >= 0){
            cr += (x + y + 2)/3 ;
        }
        ans = min(ans,cr) ;
    }
    for(int i = 0; i < N - 2 ; i ++){
        int cr = 0, x = A[i], y = A[i + 2];
        if (x < y)
            swap(x, y);
        cr = (x - y + 1)/2LL ;
        cr += y ;
        ans = min(ans,cr) ;
    }
    sort(A.begin(),A.end()) ;
    cout << min(ans,(A[0] + 1)/2 + (A[1] + 1)/2) << endl ;
}
