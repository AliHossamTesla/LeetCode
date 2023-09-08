/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    string ans;
    int l = 0, r = N - 1, prev = 0;
    while (l <= r)
    {
        if(l == r){
            if(A[l] > prev) ans.push_back('L') ;
            break ;
        }else if (A[l] > prev and A[r] > prev){
            if (A[l] < A[r])
                ans.push_back('L'), prev = A[l++];
            else if (A[l] > A[r])
                ans.push_back('R'), prev = A[r--];
            else
            {
                int cnt1 = 0 , tmpPrev1 = prev ;
                for(int i = l ; i < r ; i ++){
                    if(A[i] > tmpPrev1)
                        cnt1 ++ , tmpPrev1 = A[i] ;
                    else
                        break ;
                }
                int cnt2 = 0 , tmpPrev2 = prev ;
                for(int i = r ; i > l ; i --){
                    if(A[i] > tmpPrev2)
                        cnt2 ++ , tmpPrev2 = A[i] ;
                    else 
                        break ;
                }
                if(cnt1 > cnt2)
                    for(int i = 0 ; i < cnt1 ; i++) ans.push_back('L') ;
                else 
                    for(int i = 0 ; i < cnt2 ; i++) ans.push_back('R') ;
                break ;
            }
        }else if (A[l] > prev)
            ans.push_back('L'), prev = A[l++];
        else if (A[r] > prev)
            ans.push_back('R'), prev = A[r--];
        else
            break;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}