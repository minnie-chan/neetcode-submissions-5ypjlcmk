class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> ans;
        while(numbers[i] <= numbers[j]){
            if(numbers[i] >= numbers[j]){
                i++;
            } else if(numbers[i] + numbers[j] == target){
                ans.push_back(numbers[i]);
                ans.push_back(numbers[j]);
                return ans;
            } 
            j--;
        }
        return ans;
    }
};
