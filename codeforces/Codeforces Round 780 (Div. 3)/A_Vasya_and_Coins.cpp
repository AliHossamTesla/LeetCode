#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T --){
        int a , b ; cin >> a >> b ;
        if(a == 0) cout << 1 << endl ;
        else if(b == 0) cout << a + 1 << endl ;
        else cout << 2*b + a + 1 << endl ;
    }
}
