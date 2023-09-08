/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    vector<int> A(7);
    for (int i = 0; i < 7; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 1; i < 7; i++)
        for (int j = i + 1; j < 7; j++)
            if (A[i] + A[j] + A[0] == A.back())
            {
                cout << A[0] << " " << A[i] << " " << A[j] << endl;
                return;
            }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        solve() ;
    }
}
