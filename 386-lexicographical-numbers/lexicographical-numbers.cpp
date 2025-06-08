class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        function<void(string)> gen = [&](string i){
            if(i.size() && stoi(i) > n) return ;
            if(i.size()) ans.push_back(stoi(i)) ;
            for(char c = '0' + (i.size() == 0) ; c <= '9' ; c ++){
                gen(i + c) ;
            }
        };
        gen("");
        return ans ;
    }
};