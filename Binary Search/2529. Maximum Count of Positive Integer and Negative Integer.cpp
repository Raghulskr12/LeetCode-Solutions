class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int positiveCount = 0; // Count of positive numbers
            int negativeCount = 0; // Count of negative numbers
            
            for (int num : nums) {
                if (num > 0) 
                    positiveCount++;
                else if (num < 0) 
                    negativeCount++;
            }
            
            return max(positiveCount, negativeCount); // Return the maximum count
        }
    };
    