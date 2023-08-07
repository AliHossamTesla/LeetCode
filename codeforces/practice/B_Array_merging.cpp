#include <bits/stdc++.h>
using namespace std;

//--------------- my template -----------------------//
#define MOD 1000000007
#define ll long long

vector<int> getprimes(int size)
{
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < size; i++)
    {
        for (int p : primes)
        {
            if (p > sqrt(i))
            {
                primes.push_back(i);
                break;
            }
            if (i % p == 0)
                break;
        }
    }

    return primes;
}
//--------------- template ends ---------------------//

int n, m;
string s, ss;

void solve()
{
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    map<int, int> mp1, mp2;
    int cur = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != cur)
        {
            mp1[cur] = max(mp1[cur], l);
            cur = A[i];
            l = 1;
        }
        else
        {
            l++;
        }
    }
    mp1[cur] = max(mp1[cur], l);
    cur = 0, l = 0;
    for (int i = 0; i < n; i++)
    {
        if (B[i] != cur)
        {
            mp2[cur] = max(mp2[cur], l);
            cur = B[i];
            l = 1;
        }
        else
        {
            l++;
        }
    }
    mp2[cur] = max(mp2[cur], l);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, mp1[A[i]] + mp2[A[i]]);

    for (int i = 0; i < n; i++)
        ans = max(ans, mp1[B[i]] + mp2[B[i]]);

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}