class MedianFinder {
private:
    priority_queue<int>mx;
    priority_queue<int, vector<int>, greater<>>mn ;
    bool even = true ;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(even){
            mx.push(num) ;
            mn.push(mx.top()) ;
            mx.pop() ;
        }else{
            mn.push(num) ;
            mx.push(mn.top()) ;
            mn.pop() ;
        }
        even = !even ;
    }
    
    double findMedian() {
        if(even) return double(mn.top() + mx.top())/2.0 ;
        else return mn.top() ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */