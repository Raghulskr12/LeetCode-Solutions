class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            unordered_map<int, int> frequency;  // Map to store frequency of each number
            
            // Count occurrences of each number in the array
            for (int num : nums) {
                frequency[num]++;
            }
            
            int maxFreq = 0;  // Variable to track the highest frequency
            for (const auto& pair : frequency) {
                maxFreq = max(maxFreq, pair.second);  // Find the maximum frequency
            }
            
            int sum = 0;  // Sum of occurrences of elements with max frequency
            for (const auto& pair : frequency) {
                if (pair.second == maxFreq) {
                    sum += pair.second;
                }
            }
            
            return sum;
        }
    };
    