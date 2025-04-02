class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> prefixMax(n, 0), suffixMax(n, 0);
    
            // Compute prefix max
            prefixMax[0] = nums[0];
            for (int i = 1; i < n; i++)
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    
            // Compute suffix max
            suffixMax[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; i--)
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    
            long long ans = 0;
            for (int j = 1; j < n - 1; j++) {
                long long triplet = (long long)(prefixMax[j - 1] - nums[j]) * suffixMax[j + 1];
                ans = max(ans, triplet);
            }
    
            return max(ans, 0LL);
        }
        
        /*
        // Brute Force Approach (O(N^3))
        long long bruteForceMaximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long maxTripletValue = 0;
            
            for (int i = 0; i < n - 2; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        long long tripletValue = (long long)(nums[i] - nums[j]) * nums[k];
                        maxTripletValue = max(maxTripletValue, tripletValue);
                    }
                }
            }
            
            return maxTripletValue;
        }
        */
    };