class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;
        int carry = 0;
        
        // Starting from the least significant bit to the second most significant bit
        for (int i = s.size() - 1; i > 0; --i) {
            if ((s[i] - '0' + carry) % 2 == 0) {  // If the current bit + carry is even
                cnt++;  // It's a division by 2 step
            } else {  // If it's odd
                carry = 1;  // Increment step, which adds a carry
                cnt += 2;  // Increment step and then division by 2 step
            }
        }
        
        // For the most significant bit, if carry is present, it means one more increment
        if (carry) cnt++;
        
        return cnt;
    }
};
