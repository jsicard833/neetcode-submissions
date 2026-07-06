class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        lower.push(num);
        if (!upper.empty() && lower.top() > upper.top()) {
            upper.push(lower.top());
            lower.pop();
        }
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        }
        if (upper.size() > lower.size() + 1) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (lower.size() == upper.size()) {
            return (upper.top() + lower.top()) / 2.0;
        } else if (lower.size() > upper.size()) {
            return lower.top();
        } else {
            return upper.top();
        }
    }

private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
};
