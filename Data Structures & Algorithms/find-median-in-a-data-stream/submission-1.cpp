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
        double left = 0;
        double right = nums.size()-1;
        int n = nums.size();
            double middle = left + (right - left) / 2;
            double mr = nums[middle + 1];
            if(nums.size() % 2 == 0){
                return (nums[middle] + mr) / 2.0;
            } else {
                return nums[middle];
            }
        
        // sort
        // odd? middle
        // even? average two middles
    }
};