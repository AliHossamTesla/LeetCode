class FindSumPairs {
    vector<int>a, b; 
    unordered_map<int, int>mp ;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for(int i : b) mp[i] ++ ;
    }
    
    void add(int i, int val) {
        if(--mp[b[i]] == 0) mp.erase(b[i]) ;
        b[i] += val ;
        mp[b[i]] ++ ;
    }
    
    int count(int tot) {
        int ans = 0 ;
        for(int i = 0 ; i < a.size() ; i ++)
            if(mp.contains(tot - a[i])){
                ans += mp[tot - a[i]] ;
            }
        return ans ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */