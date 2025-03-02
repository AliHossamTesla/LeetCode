class Trie {
    Node root ;
    private class Node{
        Node[] chld ;
        int cnt;
        Node(){
            chld = new Node[26];
            cnt = 0 ;
        }
    }
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node current = root ;
        for(char c : word.toCharArray()){
            if(current.chld[c - 'a'] == null){
                current.chld[c - 'a'] = new Node();
            }
            current = current.chld[c - 'a'];
        }
        current.cnt ++ ;
    }
    
    public boolean search(String word) {
        Node current = root ;
        for(char c : word.toCharArray()){
            if(current.chld[c - 'a'] == null){
                return false ;
            }
            current = current.chld[c - 'a'];
        }
        return (current.cnt > 0);
    }
    
    public boolean startsWith(String prefix) {
        Node current = root ;
        for(char c : prefix.toCharArray()){
            if(current.chld[c - 'a'] == null){
                return false ;
            }
            current = current.chld[c - 'a'];
        }
        return true ;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */