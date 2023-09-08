#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    function<int(int, int)> divideAndConQer = [&](int n, int m) -> int{
        if(n&1) return n ;
        for(int i = 0 ; i < n/2 ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(A[i][j] != A[n - i - 1][j])
                    return n ;
        return divideAndConQer(n/2,m) ;
    };
    cout << divideAndConQer(N,M) << endl;
}
