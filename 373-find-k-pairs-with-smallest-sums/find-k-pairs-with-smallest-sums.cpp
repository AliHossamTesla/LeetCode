class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        priority_queue<array<int, 3>, vector<array<int,3>>, greater<>>gpq;
        set<array<int,2>>st ;
        gpq.push({a[0] + b[0], 0, 0}) ;
        st.insert({0, 0}) ;
        vector<vector<int>>ans;
        while(k -- && !gpq.empty()){
            auto [sm, i, j] = gpq.top() ;
            gpq.pop() ;
            ans.push_back({a[i], b[j]}) ;
            if(i < a.size() - 1 && st.count({i + 1, j}) == 0){
                gpq.push({a[i + 1] + b[j], i + 1, j}) ;
                st.insert({i + 1, j}) ;
            }
            
            if(j < b.size() - 1 && st.count({i, j + 1}) == 0){
                gpq.push({a[i] + b[j + 1], i, j + 1}) ;
                st.insert({i, j + 1}) ;
            }
        }
        return ans ;
    }
};