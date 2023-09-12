/*The blessings of God to the Prophet Muhammad*/
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
        bool ok = 0;
        int l = 0, r = N - 1;
        while (l < N and A[l] == 1)
            l++;
        while (r >= 0 and A[r] == 1)
            r--;
        int chk = 1;
        for (int i = l; i <= r; i++)
        {
            chk *= A[i];
            if (chk > 1e9)
            {
                ok = 1, cout << l + 1 << " " << r + 1 << endl;
                break;
            }
        }
        if (ok)
            continue;
        vector<int> B;
        for (int i = l; i <= r; i++)
            if (A[i] != 1)
                B.push_back(i);
        int sum = accumulate(A.begin(), A.end(), 0LL);
        int L = 1, R = 1, ans = 0;
        for (int i = 0; i < B.size(); i++)
        {
            int l = B[i], prod = 1, s = 0;
            for (int j = i; j < B.size(); j++)
            {
                int r = B[j];
                prod *= A[r];
                s += A[r] - 1;
                int tmp = sum - (r - l + 1) - s + prod;
                if (tmp > ans)
                {
                    ans = tmp;
                    L = l + 1;
                    R = r + 1;
                }
            }
        }
        cout << L << " " << R << endl;
    }
}