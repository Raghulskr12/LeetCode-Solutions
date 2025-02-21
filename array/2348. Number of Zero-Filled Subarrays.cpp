class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            long long ans = 0;  
            long long temp = 0;  // Counts consecutive zeros
            
            // First solution: Count contiguous zero subarrays
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    temp++;  // Increase zero count
                } else {
                    temp = 0;  // Reset if nonzero is found
                }
                ans += temp;  // Add to answer (sum of 1+2+3...n for each sequence)
            }
            return ans;
    
            /*
            Second solution: Using an extra array to store zero sequences
    
            vector<long long> zeroLengths;
            long long count = 0;
            long long ans = 0;
    
            // Collect lengths of contiguous zero sequences
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    count++;
                } else {
                    zeroLengths.emplace_back(count);
                    count = 0;
                }
                if (i == nums.size() - 1) {  // Edge case: last element is zero
                    zeroLengths.emplace_back(count);
                }
            }
    
            // Sum of series formula: (n * (n + 1)) / 2 for each zero sequence
            for (int i = 0; i < zeroLengths.size(); i++) {
                ans += (zeroLengths[i] * (zeroLengths[i] + 1)) / 2;
            }
            
            return ans;
            */
        }
    };
    