class Trie {
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
    void insert(string word) {
        Node *cr = root ;
        for(auto c : word){
            if(cr->chld[c - 'a'] == nullptr){
                cr->chld[c - 'a'] = new Node() ;
            }
            cr = cr->chld[c - 'a'] ;
        }
        cr->is_word = true ;
    }
    
    bool search(string word) {
        Node *cr = root ;
        for(auto c : word){
            if(cr->chld[c - 'a'] == nullptr) return false ;
            cr = cr->chld[c - 'a'] ;
        }
        return cr->is_word ;
    }
    
    bool startsWith(string prefix) {
        Node *cr = root ;
        for(auto c : prefix){
            if(cr->chld[c - 'a'] == nullptr) return false ;
            cr = cr->chld[c - 'a'] ;
        }
        
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */