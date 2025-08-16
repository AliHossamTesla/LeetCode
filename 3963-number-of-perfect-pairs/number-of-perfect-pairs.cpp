#define i64 long long
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        vector<int>a;
        for(int i : nums) a.push_back(abs(i)) ;
        sort(begin(a), end(a)) ;
        i64 ans = 0 ;
        // a 
        for(int i = 0 ; i < a.size() ; i ++){
            int j = upper_bound(begin(a), end(a), 2*a[i]) - begin(a) ;
            // j - i - 1
            ans += j - i - 1;
        }
        return ans ;
    }
};