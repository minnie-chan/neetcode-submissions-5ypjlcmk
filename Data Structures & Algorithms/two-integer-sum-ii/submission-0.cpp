class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int right = numbers.size() - 1;

       int left = 0 ;
        
       while( left < right ){
        int lef = numbers[left];
        int righ = numbers[right];
        int sum = lef + righ; 

            if(sum > target ){
                
                right --;
            } else if(sum < target ){
                left ++;
            }
            if(sum == target ){
                return {left+1,right+1};
            }
            
       }
    }
};
