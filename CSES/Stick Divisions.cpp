// Problem: Stick Divisions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1161
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By : Ali Hossam
/*
 أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 */
#include <bits/stdc++.h>
#define Wady ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define testCase int testCase; cin >> testCase; while (testCase--)
#define el "\n"
#define sp " "
#define I(i,n) " \n"[i == n]
#define foreach(v1) for (auto &i : v1)
#define pq priority_queue
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
using ll = long long;
using ld = long double;
using str = string;
#define f first
#define s second
#define clr(x,y) memset(x,y,sizeof(x))
ll n, k, m;
ll i, j, i1; // for iterations
int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};
struct HuffmanNode{
	int val ;
	HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(int val) : val(val) , left(nullptr), right(nullptr) {}
};
struct Compare{
	bool operator()(HuffmanNode* lhs, HuffmanNode* rhs){
		return lhs->val > rhs -> val ;
	}
};
HuffmanNode* buildHuffmanTree(const vector<ll>& v) {
	pq<HuffmanNode*, vector<HuffmanNode*>, Compare> Q ;
	foreach(v){
		Q.push(new HuffmanNode(i)) ;
	}
	while(Q.size() > 1){
		HuffmanNode* left = Q.top();
        Q.pop();
        HuffmanNode* right = Q.top();
        Q.pop();
        HuffmanNode* internal = new HuffmanNode(left->val + right->val);
        internal->left = left;
        internal->right = right;
        Q.push(internal);
	}
	return Q.top() ;
}
void preOrderTraversal(HuffmanNode* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
ll sumNodesWithBothChildren(HuffmanNode* root) {
    if (root == nullptr)
        return 0;

    // Initialize the sum to 0
    ll sum = 0;

    // Check if the current node has both left and right children
    if (root->left && root->right) {
        sum += root->val;
    }

    // Recursively calculate the sum for the left and right subtrees
    sum += sumNodesWithBothChildren(root->left);
    sum += sumNodesWithBothChildren(root->right);

    return sum;
}
void doYourJop()
{
	cin >> m >> n ;
	vector<ll>v(n) ;
	foreach(v)
		cin >> i ;
	sort(all(v)) ;
	HuffmanNode* root = buildHuffmanTree(v);
	ll ans = sumNodesWithBothChildren(root) ;
	cout << ans << el ;
}
int main()
{
    // صلي علي سيدنا محمد
    Wady
    // testCase
        doYourJop();
    return 0;
}
/*
ispire from 
Huffman coding is a popular data compression algorithm 
that creates variable-length prefix codes to represent 
different characters in a message based on their frequency.
Characters with higher frequency get shorter codes,
while less frequent characters get longer codes.
Below is a simple implementation of Huffman coding in C++.
For simplicity, we'll assume the input contains only ASCII characters.
*/
/*
simple solution 
link : https://usaco.guide/problems/cses-1161-stick-division/solution

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	cin >> x >> n;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		PQ.push(a);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int a = PQ.top();
		PQ.pop();
		int b = PQ.top();
		PQ.pop();
		PQ.push(a + b);
		ans += a + b;
	}

	cout << ans << "\n";
	return 0;
}
*/