/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int zer , one ;
    cin >> zer >> one ;
    int N = zer + one ;
    if(one > 2*(zer + 1) or zer > one + 1){
        cout << -1 << endl ;
        return 0 ;
    }if(zer >= one){
        for(int i = 0 ; i < N ; i++){
            if (!(i & 1) and zer) cout << 0, zer--;
            else cout << 1;
        }
    }else{
        int x = one - zer - 1;
        int y = one - 2*x;
        for(int i = 0 ; i < zer ; i ++){
            x ? (cout << "11" ,x --) : (cout <<"1" ,y --) ;
            cout << "0" ;
        }
        if(x) cout << "11" ;
        if(y) cout << "1" ;
    }
}
