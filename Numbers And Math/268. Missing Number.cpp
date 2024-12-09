class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = 0;  // Sum of all numbers from 0 to n
        int actualSum = 0;    // Sum of all numbers present in the array

        // Calculate the expected sum of numbers from 0 to n
        for (int i = 0; i < nums.size() + 1; i++) {
            expectedSum += i;
        }

        // Calculate the actual sum of numbers in the array
        for (int i = 0; i < nums.size(); i++) {
            actualSum += nums[i];
        }

        // The missing number is the difference between the expected and actual sum
        return expectedSum - actualSum;
    }
};
