class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int>q; 
        vector<int>idx(p.size()) ;
        iota(begin(idx), end(idx), 0) ;
        sort(begin(idx), end(idx), [&](int i, int j){
            return c[i] < c[j] ;
        });
        int i = 0 ;
        while(k){
            while(i < p.size() && c[idx[i]] <= w){
                q.push(p[idx[i++]]) ;
            }
            if(q.empty()) break ;
            while((i == p.size() || c[idx[i]] > w) && !q.empty() && k){
                k -- ;
                w += q.top() ;
                q.pop() ;
            }
        }
        return w ;
    }
};