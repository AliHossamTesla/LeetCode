/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    const int MOD = 1e9 + 7;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        sort(A.begin(), A.end());
        int res = A[0];
        for (int i = 1; i < N; i++)
            res &= A[i];
        int cnt = count(A.begin(), A.end(), A[0]);
        if (res != A[0] or cnt <= 1)
        {
            cout << 0 << endl;
            continue;
        }
        auto mult = [&](int a, int b) -> int
        { return ((a % MOD) * (b % MOD)) % MOD; };
        function<int(int)> factorial = [&](int fc) -> int
        {
            if (fc <= 0)
                return 1;
            return mult(fc, factorial(fc - 1));
        };
        int ans = mult(cnt, (cnt - 1));
        ans = mult(ans, factorial(N - 2));
        cout << ans << endl;
    }
}
/*
hint1 : what is the characteristics of a good sequence ?
assume we have to array And_pref and And_suf
should for every i form 1 to n - 1
And_pref[i] = And_suf[i + 1] ;
so And_pref[1] should equel to And_suf[2] which And_pref[1] = A[1] ; *note we start index from 1
if we go forward in and prefix we note that we have two option prefix decrease or still constant
so And_pref[2] <= And_pref[1] = And_suf[2] <= And_suf[3]        *And_pref[1] = A[1]
so the only solution for equation that And_pref[2] = And_pref[1] = And_suf[2] = And_suf[3] = A[1] 
so the correct sequence is A[1] = A[N] and A[i] is super mask of A[0] i from 2 to N - 1 ;
we can check super mask by chose tha A[0] to be the minimum and the all and of array is equal to minimum

so the answer is : (cnt*(cnt - 1)*(N - 2)!) % 1e9 + 7 ;
where :
cnt : frequency of minimum (A[0]) ;
N : size of array .

what is super mask ?
if a = 101110 and b = 100010 
we can say a super mask of b as a has at least number of ones in b .
*/