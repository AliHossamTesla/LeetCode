class Solution {
public:
    struct Event{
        int st , en ;
        bool operator<(const Event&y){
            if(st == y.st)
                return en < y.en ;
            return st < y.st ;
        }
    };
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size() ;
        vector<Event>ev(n);
        int mx = 0 ;
        for(int i = 0 ; i < n ; i ++)
            ev[i].st = events[i][0] , ev[i].en = events[i][1] ,mx = max(mx,events[i][1]);
        sort(ev.begin(),ev.end()) ;
        int j = 0 , ans = 0 ;
        priority_queue<int,vector<int>,greater<int>>pQ ;
        for(int i = 1 ; i <= mx ; i ++)
        {
            while(!pQ.empty() and pQ.top() < i)
                pQ.pop() ;
            while(j < n and ev[j].st == i)
                pQ.push(ev[j ++].en) ;
            if(!pQ.empty())
                pQ.pop() , ans ++ ;
        }
        return ans ;
    }
};