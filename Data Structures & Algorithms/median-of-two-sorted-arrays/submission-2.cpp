#include <climits>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size() ){
            return findMedianSortedArrays(nums2, nums1);
        }
        const vector<int>& A = nums1;
        const vector<int>& B = nums2;
        int m = A.size();
        int  n = B.size();
        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;
        while(left <= right ){
            int i = (left + right ) / 2;
            int j = half - i;
            
            int leftA  = (i == 0) ? INT_MIN : A[i - 1];
            int rightA = (i == m) ? INT_MAX : A[i];
            int leftB  = (j == 0) ? INT_MIN : B[j - 1];
            int rightB = (j == n) ? INT_MAX : B[j];

            if(leftA <= rightB && leftB <= rightA){
                 if ((m + n) % 2 == 1)  
                 return static_cast<double>(max(leftA, leftB));
                  else                                  
                 return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            else if (leftA > rightB) {
    right = i - 1;          // i too big → move left
        } else { // (leftB > rightA)
    left = i + 1;           // i too small → move right
            }
        }
        
        return 0.0; 
    }
};
