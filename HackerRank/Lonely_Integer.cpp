#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    int xr = 0 ;
    for(int i =0 ;i < n ; i ++)
    {
        int val ;
        cin >> val ;
        xr ^= val ;
    }
    cout << xr << "\n" ;
    return 0;
}
