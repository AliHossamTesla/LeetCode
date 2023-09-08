#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , r , av ;
    cin >> N >> r >> av ;
    vector<pair<int,int>>A(N) ;
    int sum = 0 ;
    for(int i = 0 ; i < N ; i++)
        cin >> A[i].first >> A[i].second ,sum += A[i].first;
    sum = (av * N) - sum ;
    if(sum <= 0){cout << 0 << endl ; return 0 ;}
    sort(A.begin(),A.end(),[](const pair<int,int>& a,const pair<int,int>&b){
        if(a.second == b.second) return a.first < b.first ;
        return a.second < b.second ;
    });
    int ans = 0 ;
    for(int i = 0 ; i < N and sum > 0 ; i ++){
        int cr = min(sum , r - A[i].first) ;
        ans += cr * A[i].second ;
        sum -= cr ;
    }
    cout << ans << endl ;
}
