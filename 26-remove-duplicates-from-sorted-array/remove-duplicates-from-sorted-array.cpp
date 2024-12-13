class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int slow = 1, fast = 1 ;
        // vector<bool>vis(201, false) ;
        for(; fast < a.size() ; fast ++){
            if(a[fast] != a[fast - 1]){
                a[slow ++] = a[fast] ;
            }
        }
        return slow ;
    }
};