class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0; 
    //idk how to start i was thinkign of starting by the end and reverse it but now that i type it, it dosent make sense

        for(int i = 0; i < 32; i++){
            int bit = n & 1;
            ans <<= 1;
            ans |= bit;
            n >>= 1;
        }
        
        return ans;
    }
};
