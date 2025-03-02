class Solution {
    public:
        // Helper function to check if 'divisor' can divide all elements to meet the threshold 't'
        bool isValidDivisor(vector<int>& nums, int threshold, int divisor) {
            int sum = 0;
            for (int num : nums) {
                sum += ceil((double)num / (double)divisor); // Compute the sum of division results
            }
            return sum <= threshold;
        }
    
        int smallestDivisor(vector<int>& nums, int threshold) {
            int maxElement = *max_element(nums.begin(), nums.end()); // Get the maximum element
            int low = 1, high = maxElement;
    
            // Binary search to find the smallest divisor
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (isValidDivisor(nums, threshold, mid)) {
                    high = mid - 1; // Try smaller divisors
                } else {
                    low = mid + 1;  // Increase divisor if condition is not met
                }
            }
    
            return low; // The smallest valid divisor
        }
    };
    