class Solution {
public:
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        sort(b.begin(), b.end());
        int n = a.size(), m = b.size();
        auto calc = [&](long long y, long long x){
            int l = 0, r = m - 1 ;
            while(l <= r){
                int md = l + (r - l)/2 ;
                if((y >= 0 && b[md] * y <= x) || (y < 0 && b[md] * y > x)) l = md + 1 ;
                else r = md - 1 ;
            }
            return (y >= 0 ? l : m - l) ;
        };
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = left + (right - left)/2;
            long long cnt = 0 ;
            for(int i : a){
                cnt += calc(i, mid) ;
            }
            if (cnt >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
