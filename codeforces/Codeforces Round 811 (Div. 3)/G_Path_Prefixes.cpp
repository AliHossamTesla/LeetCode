/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
	while(T--){
		int N;
		cin >> N;
		vector<pair<int, pair<int, int>>> adj[N + 1];
		for (int i = 2; i <= N; i++){
			int u, a, b;
			cin >> u >> a >> b;
			adj[u].push_back({i, {a, b}});
		}
		vector<int> A(N + 1, 0), B(N + 1, 0), ans(N + 1, 0),seQ;
		function<void(int, int)> dfs = [&](int u, int cnt) -> void{
			for (auto v : adj[u])
			{
				A[v.first] = A[u] + v.second.first;
				B[v.first] = B[u] + v.second.second;
				seQ.push_back(B[v.first]);
				ans[v.first] = upper_bound(seQ.begin(), seQ.end(),A[v.first]) - seQ.begin();
				dfs(v.first, cnt + 1);
				seQ.pop_back() ;
			}
		};
		dfs(1, 0);
		for (int i = 2; i <= N; i++)
			cout << ans[i] << " \n"[i == N];
	}
}
