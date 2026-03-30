class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0; int right = s.size() -1;

        while(left < right){
            if(s[left] == s[right]) {
                left ++;
                right --;
            } else {
            return isPal(left,right-1,s) || isPal(left+1,right,s);
            }
            
            
        }

        return true;
    }

    bool isPal(int i, int j, string& s) {
      while(i < j){
        if(s[i] != s[j]){
        return false;
        } else if(s[i] == s[j]){
            i ++ ;
            j -- ;
        }
      }
      return true;
    }
};