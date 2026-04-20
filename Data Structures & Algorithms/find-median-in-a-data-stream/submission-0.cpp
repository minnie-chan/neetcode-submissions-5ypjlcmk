class MedianFinder {
private:
    vector<int> nums;
public:
    MedianFinder() {}

    void addNum(int num) {
        // store num
        nums.push_back(num);
    }

    double findMedian() {
        // sort
        // odd? middle
        // even? average two middles
    }
};