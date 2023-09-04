/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 1:26pm 23/6/2023 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        vector<int> B(A.begin(), A.end());
        sort(B.begin(), B.end());
        bool ok = 1;
        if(A.size()&1){
            for (int i = 1; i < A.size() - 1; i += 2)
            {
                if ((A[i] == B[i] and A[i + 1] == B[i + 1]) or (A[i] == B[i + 1] and A[i + 1] == B[i]))
                    continue;
                ok = 0;
            }
        }else{
            for (int i = 0; i < A.size() - 1; i += 2)
            {
                if ((A[i] == B[i] and A[i + 1] == B[i + 1]) or (A[i] == B[i + 1] and A[i + 1] == B[i]))
                    continue;
                ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}