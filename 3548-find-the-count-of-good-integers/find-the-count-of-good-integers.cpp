class Solution {
public:
    vector<string>cr ;
    long long fact[20];
    long long inv_fact[20] ;
    unordered_set<string>st ;
    void init() {
        fact[0] = 1;
        for (int i = 1; i < 20; ++i)
            fact[i] = i * fact[i - 1];
    }
    long long comb(string s){
        sort(begin(s), end(s)) ;
        if(st.contains(s)) return 0 ;
        st.insert(s);
        map<char, int> freq;
        for (char c : s) freq[c]++;

        int len = s.size();
        long long total = fact[len];
        for (auto [_, f] : freq)
            total /= fact[f];

        // remove invalid ones starting with 0
        if (freq['0'] == 0) return total;

        freq['0']--;
        long long bad = fact[len - 1];
        for (auto [_, f] : freq)
            bad /= fact[f];

        return total - bad;
    }
    void gen(string s, int n){
        if(s.size() == (n + 1)/2){
            string tmp = "" ;
            if(s.back() == '0') return ;
            for(int i = s.size() - 1 ; i >= (n & 1) ; i --){
                tmp.push_back(s[i]) ;
            }
            cr.push_back(tmp + s) ;
            return ;
        }
        for(char c = '0' ; c <= '9' ; c ++){
            gen(s + c, n);
        }
    }
    long long countGoodIntegers(int n, int k) {
        init();
        gen("", n);
        int ans = 0 ;
        for(string i : cr){
            if(stoll(i) % k == 0){
                ans += comb(i);
            }
        }
        return ans ;
    }
};