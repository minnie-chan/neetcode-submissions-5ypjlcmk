class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        int end_a = a.size() -1;
        int end_b = b.size() -1;

        while(end_a >= 0 || end_b >= 0 || carry){
            int sum = carry;
            if(end_a >= 0){
               sum += a[end_a] - '0';
                end_a --;
            }
            if(end_b >= 0){
               sum += b[end_b] - '0';
                end_b--;
            }
            int re = sum % 2;
            res += re + '0';
            carry = sum / 2; 
        }
        reverse(res.begin(), res.end());
        return res;
    }
};