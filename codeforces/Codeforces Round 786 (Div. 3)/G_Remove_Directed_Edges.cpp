/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 1:26pm 23/6/2023 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
using namespace __gnu_pbds;
template <typename T> // T -> (can be integer, float or pair of int etc.)
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , M , Q ; cin >> N >> M >> Q ;
    ordered_set<int>st ;
    for(int i = 0; i < N ; i ++)
        for(int j = 0 ; j < M ; j ++){
            char C ; cin >> C ;
            if(C == '*')
                st.insert(j*M+i) ;
        }
    while(Q--){
        int x , y ; cin >> x >> y ; x -- ; y -- ;
        if(st.find(y*M+x) == st.end())
            st.insert(y * M + x);
        else
            st.erase(y * M + x);
        cout << st.size() - st.order_of_key(st.size()) << endl ;
    }
}
