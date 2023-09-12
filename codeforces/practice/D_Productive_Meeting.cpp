/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        priority_queue<pair<int,int>>Q ;
        for(int i = 0 ; i < N ; i ++){
            int val ; cin >> val ; 
            if(val > 0){
                Q.push({val,i}) ;
            }
        }
        vector<pair<int,int>>ans ;
        while (Q.size() >= 2){
            pair<int, int> fi = Q.top();
            Q.pop();
            pair<int, int> se = Q.top();
            Q.pop();
            ans.push_back({fi.second,se.second}) ;
            if(fi.first > 1)
                Q.push({fi.first - 1,fi.second}) ;
            if(se.first > 1)
                Q.push({se.first - 1,se.second}) ;
        }
        cout << ans.size() << endl;
        for(int i = 0 ; i < ans.size() ; i++)
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl ;
    }
}
