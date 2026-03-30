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
        sort(nums.begin(), nums.end());
        int n = nums.size();
            if(nums.size() % 2 == 0){
                return (nums[n/2 - 1] + nums[n / 2]) / 2.0;
            } else {
                return nums[n / 2];
            }
        
        // sort
        // odd? middle
        // even? average two middles
    }
};