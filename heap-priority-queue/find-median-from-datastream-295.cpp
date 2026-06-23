struct Compare {
    bool operator()(int a, int b) {
        // Return true if "a" should have lower priority than "b"
        // For a min-heap, the element with the LARGER value goes to the bottom
        return a > b; 
    }
};

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, Compare> minHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() < minHeap.size()){
            if(minHeap.top() < num){
                int swap = minHeap.top();
                minHeap.pop();
                maxHeap.push(swap);
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(maxHeap.size() > 0 && maxHeap.top() > num){
                int swap = maxHeap.top();
                maxHeap.pop();
                minHeap.push(swap);
                maxHeap.push(num);
            }
            else{
                minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return static_cast<double>(minHeap.top() + maxHeap.top()) / 2;
        }
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



 