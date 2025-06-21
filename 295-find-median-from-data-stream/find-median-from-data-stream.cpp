class MedianFinder {
public:
    priority_queue<int> pq_left;
    priority_queue<int, vector<int>, greater<int>> pq_right;

    MedianFinder() {
    }
    
    void addNum(int num) {
        // if(pq_left.empty()){
        //     pq_left.push(num);
        //     return;
        // }
        // if(pq_right.empty()){
        //     pq_right.push(num);
        //     return;
        // }
        // if(pq_left.size() == pq_right.size()){
        //     pq_left.push(pq_right.top());
        //     pq_right.pop();
        //     pq_right.push(num);
        // }else{
        //     pq_right.push(num);
        // }

        if(pq_left.empty() || num < pq_left.top()){
            pq_left.push(num);
        }else{
            pq_right.push(num);
        }

        if(abs((int)pq_left.size() - (int)pq_right.size()) > 1){
            pq_right.push(pq_left.top());
            pq_left.pop();
        }else if(pq_left.size() <  pq_right.size()){
            pq_left.push(pq_right.top());
            pq_right.pop();
        }
    }
    
    double findMedian() {
        if(pq_left.size() > pq_right.size()){
            // cout << "1: " << pq_left.top() << endl;
            return pq_left.top();
        }else{
            // cout << "2: " << (pq_left.top() + pq_right.top())/2 << endl;
            // cout << "2a: " << pq_left.top() << endl;
            // cout << "2b: " << pq_right.top() << endl;
            return (double)(pq_left.top() + pq_right.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */