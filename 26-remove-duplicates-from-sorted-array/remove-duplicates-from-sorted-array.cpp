class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int slow = 0, fast = 0 ;
        vector<bool>vis(201, false) ;
        for(; fast < a.size() ; fast ++){
            if(!vis[a[fast] + 100]){
                vis[a[fast] + 100] = true ;
                swap(a[fast], a[slow ++]) ;
            }
        }
        return slow ;
    }
};