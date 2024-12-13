class Solution {
public:
    struct Node{
        Node* chld[26]{} ;
        bool is_word ;
        Node():is_word(false){
            fill(begin(chld), end(chld), nullptr);
        }
    };
    void insert_word(Node *root, string s){
        Node* current_node = root ;
        for(auto c : s){
            if(current_node->chld[c - 'a'] == nullptr){
                current_node->chld[c - 'a'] = new Node() ;
            }
            current_node = current_node->chld[c - 'a'] ;
        }
        current_node->is_word = true ;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Node *root = new Node() ;
        for(auto c : wordDict){
            insert_word(root, c) ;
        }
        
        int n = s.size() ;
        vector<bool>dp(n + 1);
        dp[0] = true ;
        for(int i = 1 ; i <= n ; i ++){
            if(dp[i - 1]){
                Node *current_node = root ;
                for(int j = i - 1 ; j < n ; j ++){
                    char c = s[j] ;
                    if(current_node->chld[c - 'a'] == nullptr){
                        break ;
                    }
                    current_node = current_node->chld[c - 'a'] ;
                    if(current_node->is_word){
                        dp[j + 1] = true ;
                    }
                }
            }
        }
        return dp[n] ;
    }
};