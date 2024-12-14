class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        vector<int>ans ;
        int carry = 1 ;
        for(int i = d.size() - 1 ; i >= 0 ; i --){
            d[i] += carry ;
            ans.push_back(d[i] % 10) ;
            carry = d[i]/10 ;
        }
        if(carry) ans.push_back(carry) ;
        reverse(begin(ans), end(ans)) ;
        return ans ;
    }
};