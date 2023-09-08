#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename T>
void chkmax(T &x, T y){if (x < y)x = y;}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>cnt(N,0) ;
        int total = 0 ;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char c;
                cin >> c;
                cnt[(i - j + N) % N] += (c == '1');
                total += (c == '1');
            }
        }
        int cr = 0 ;
        for(int i = 0 ; i < N ; i ++) chkmax(cr,cnt[i]) ;
        cout << total + N - 2*cr << endl ;
    }
}
