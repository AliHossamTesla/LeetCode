/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , K ; cin >> N >> K ;
    int lft = N -  K*(K + 1)/2;
    if(lft < 0){
        cout << "NO\n";
        return 0 ;
    }
    int ex = lft / K , rem = lft % K ;
    vector<int>A(K);
    for (int i = 0; i < K; i++)
        A[i] = i + 1 + ex;
    for(int i = K - 1 ; i >= 0 and rem > 0 ; i --){
        while(rem > 0 and (i == 0 or A[i] < A[i - 1] * 2)){
            for(int j = i ; j < K and rem > 0 ; j ++){
                while(rem > 0 and (j == 0 or A[j] < A[j - 1] * 2))
                    A[j] ++ , rem -- ;
            }
        }
    }
    for(int i = 0 ; i < K - 1 ; i ++)
        if(!(A[i] < A[i + 1] and A[i + 1] <= A[i]*2LL)){
            cout << "NO\n";
            return 0 ;
        }
    cout << "YES\n";
    for(int i = 0 ; i < K ; i ++)
        cout << A[i] << " \n"[i + 1 == K] ;
}
