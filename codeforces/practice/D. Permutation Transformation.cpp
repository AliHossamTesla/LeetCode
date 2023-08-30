// Problem: D. Permutation Transformation
// Contest: Codeforces - Codeforces Round 702 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1490/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*The blessings of God to the Prophet Muhammad
 *  written by : @Tesla
 *  in 9:29pm 29/8/2023 */
#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define endl "\n" ;
struct TreeNode{
	int val ,d;
	TreeNode* left ;
	TreeNode* right ;
	TreeNode(int val,int d) : val(val),d(d),left(nullptr),right(nullptr){}
};
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T ; cin >> T ;
	while(T--){
		int N ; cin >> N ;
		vector<int>A(N) ;
		for(int i = 0 ; i < N ; i ++)
			cin >> A[i] ;
		function<TreeNode*(int,int,int)> buildTree = [&](int left,int right,int depth) -> TreeNode*{
			if(left > right)
				return nullptr ;
			int maxIdx = left ;
			for(int i = left + 1 ;i <= right ; i ++){
				if(A[i] > A[maxIdx])
					maxIdx = i ;
			}
			TreeNode* root = new TreeNode(A[maxIdx],depth) ;
			root->left = buildTree(left,maxIdx - 1,depth + 1) ;
			root->right = buildTree(maxIdx + 1,right,depth + 1) ;
			return root ;
		};
		TreeNode* root = buildTree(0,N - 1,0) ;
		vector<int>dep(N + 1,0) ;
		function<void(TreeNode*)> findDepth = [&](TreeNode* root)->void{
			if (root) {
				dep[root->val] = root ->d ;
				findDepth(root->left);
				findDepth(root->right);
			}
		};
		findDepth(root) ;
		for(int i = 1 ; i <= N ; i ++)
			cout << dep[A[i - 1]] << " \n"[i == N] ;
	}
}