class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x ;
        int anwser;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if((long long)middle * middle > x){
                right = middle -1;
            } else if((long long) middle * middle < x ){
                left = middle + 1;
                anwser = middle; 
            } else {return middle;}
          
        }
       return anwser;
    }
};