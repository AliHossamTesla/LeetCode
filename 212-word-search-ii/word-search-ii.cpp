class Solution {
private:
    struct Node{
        Node *ch[26]{} ;
        bool is_word;
        Node():is_word(false){
            fill(ch,ch+26, nullptr) ;
        }
    };
    Node *root = new Node() ;
    void insert(string s){
        Node *cr = root ;
        for(auto c : s){
            if(cr->ch[c - 'a'] == nullptr){
                cr->ch[c - 'a'] = new Node() ;
            }
            cr = cr->ch[c - 'a'] ;
        }
        cr->is_word = true ;
    }
public:
    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {
        for(auto s : words){
            insert(s) ;
        }
        int dx[]{1,0,-1,0}, dy[]{0,-1,0,1} ;
        int n = a.size(), m =  a[0].size() ;
        vector<string>ans ;
        
        auto valid = [&](int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m ;
        };
        
        function<void(int, int, Node *, string)> floodfill = [&](int i, int j, Node *r, string s){
            if(a[i][j] == '#'|| r->ch[a[i][j] - 'a'] == nullptr) return ;
            s.push_back(a[i][j]) ;
            r = r->ch[a[i][j] - 'a'] ;
            if(r->is_word){
                ans.push_back(s) ;
                r->is_word = false ;
            }
            
            char prev = a[i][j] ;
            a[i][j] = '#' ;
            for(int di = 0 ; di < 4 ; di ++) if(valid(i + dx[di], j + dy[di])){
                int ni = i + dx[di], nj = j + dy[di] ;
                floodfill(ni, nj, r, s) ;
            }
            a[i][j] = prev ;
        };
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                floodfill(i, j, root, "") ;
            }
        }
        return ans ;
    }
};