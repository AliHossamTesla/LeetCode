/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N ; cin >> N ;
	vector<pair<int,int>>A(N) ;
	for(int i = 0 ; i < N ; i++)
		cin >> A[i].first >> A[i].second ;
	sort(A.begin(), A.end(), [](pair<int, int> & l, pair<int, int>&r){
		if(l.first == r.first) return l.second < r.second ;
		return l.first < r.first ;
	});
	int cr = 0 ;
	for(int i = 0 ; i < N ; i++)
		cr = min(A[i].first,(cr <= A[i].second ? A[i].second : INT_MAX)) ;
	cout << cr << endl;
}
