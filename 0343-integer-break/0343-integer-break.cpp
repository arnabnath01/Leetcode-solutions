class Solution {
public:
    int integerBreak(int n) {
        // handle base cases
        if (n == 2) return 1;
        if (n == 3) return 2;

        // Dynamic programming table to store maximum products
        vector<int> dp(n + 1, 0);

        // Base cases for numbers 1, 2, and 3 -only for computing for rest of numbers-
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        // Fill the dynamic programming table for larger numbers
        for (int num = 4; num <= n; ++num) {
            int dpForNum = 0;
            // Iterate through smaller numbers to calculate the maximum product
            for (int subNum = 1; subNum <= num / 2; ++subNum) {
                dpForNum = max(dpForNum, dp[subNum] * dp[num - subNum]);
            }
            // Update the maximum product for the current number
            dp[num] = dpForNum;
        }

        return dp[n];
    }
};