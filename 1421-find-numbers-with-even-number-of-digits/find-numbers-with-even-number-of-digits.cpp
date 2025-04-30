class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0 ;
        for(int i : nums) cnt += to_string(i).size() % 2 == 0 ;
        return cnt ;
    }
};