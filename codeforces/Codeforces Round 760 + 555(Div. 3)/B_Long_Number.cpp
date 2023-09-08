/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; cin >> N ;
    string s ; cin >> s; 
    unordered_map<char,char>mp;
    for(int i = '1'; i <= '9'; i++)
        cin >> mp[i] ;
    bool start = 0 ;
    for(int i = 0 ; i < s.size() ; i ++){
        if(start){
            if(mp[s[i]] >= s[i])
                s[i] = mp[s[i]];
            else
                break ;
        }else if(mp[s[i]] > s[i]){
            s[i] = mp[s[i]]; 
            start = 1 ;
        }
    }
    cout << s << endl ;
}
