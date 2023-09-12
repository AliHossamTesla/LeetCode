/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        sort(A.begin(), A.end());
        int MEX = 0;
        for (int i = 0; i < N; i++) if(MEX++ != A[i]) break;
        MEX = max(0LL, MEX - 1);
        cout << MEX << endl;
        cin >> MEX;
        while (~MEX){
            cout << MEX << endl;
            cin >> MEX;
        }
    }
}
