class WordDictionary {
private:
    struct Node{
        Node *chld[26]{} ;
        bool is_word;
        Node():is_word(false){
            fill(chld,chld+26, nullptr) ;
        }
    };
    Node *root = new Node() ;
public:
    void addWord(string word) {
        Node *cr = root ;
        for(auto c : word){
            if(cr->chld[c - 'a'] == nullptr){
                cr->chld[c - 'a'] = new Node() ;
            }
            cr = cr->chld[c - 'a'] ;
        }
        cr->is_word = true ;
    }
    
    bool dfs(string s, int i, Node *r){
        if(r == nullptr) return false ;
        if(i == s.size()) return r->is_word ;
        if(s[i] == '.'){
            for(int j = 0 ; j < 26 ; j ++) 
                if(dfs(s, i + 1, r->chld[j])) return true ;
            return false ;
        }
        return dfs(s, i + 1, r->chld[s[i] - 'a']) ;
    }
    bool search(string word) {
        return dfs(word, 0, root) ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */