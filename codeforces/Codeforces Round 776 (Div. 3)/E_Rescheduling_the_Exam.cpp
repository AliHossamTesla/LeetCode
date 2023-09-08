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
        int N, d;
        cin >> N >> d;
        vector<int> A(N + 2, 0);
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        A[N + 1] = d;
        int l = 0, r = d;
        auto fn = [&](int mid) -> bool
        {
            int tmp = 1, prev = A[0], aval = 0;
            for (int i = 1; i <= N; i++)
            {
                if (A[i] - prev - 1 < mid)
                {
                    if (tmp)
                        tmp = 0;
                    else
                        return 0;
                }
                else
                {
                    int dif = A[i] - prev - 2;
                    if (dif / 2 >= mid)
                        aval = 1;
                    prev = A[i];
                }
            }
            if ((A[N + 1] - prev - 1) >= mid)
                aval = 1;
            if (aval or tmp)
                return 1;
            prev = A[N], aval = 0, tmp = 1;
            for (int i = N - 1; i >= 0; i--)
            {
                if (prev - A[i] - 1 < mid)
                {
                    if (tmp)
                        tmp = 0;
                    else
                        break;
                }
                else
                {
                    int dif = prev - A[i] - 2;
                    if (dif / 2 >= mid)
                        aval = 1;
                    prev = A[i];
                }
            }
            if ((A[N + 1] - A[N] - 1) >= mid)
                aval = 1;
            if (aval or tmp)
                return 1;
            return 0;
        };
        int ans = 1;
        while (l <= r)
        {
            int mid = l + (r - l + 1) / 2;
            if (fn(mid))
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
}