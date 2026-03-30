class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.size() - 1;
     

               

                
               
                 while(left < right ){
             

                         if(!isalnum(s[left])) {
                    left ++;
                    //question you want meto check left and right if  it is not a number or letter right ? 
                    continue;
                }
                if(!isalnum(s[right])) {
                    right --;
                    continue;
                }

                 if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                    left ++; // idk what inwards means
                        right --;
                 }            
                
        
        return true;
    }
};
