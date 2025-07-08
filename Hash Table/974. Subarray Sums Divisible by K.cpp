class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currentSum = 0;                         // Running prefix sum
        int remainder = 0;                          // Stores remainder of currentSum % k
        int subarrayCount = 0;                      // Number of subarrays divisible by k
        unordered_map<int, int> remainderFreq;      // Maps each remainder to its frequency

        remainderFreq[0] = 1; // A sum divisible by k from the start is counted

        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            remainder = currentSum % k;

            // Handle negative remainder by converting to positive equivalent
            if (remainder < 0) remainder += k;

            // If the same remainder has been seen before,
            // it means there are subarrays ending at current index that are divisible by k
            if (remainderFreq.find(remainder) != remainderFreq.end()) {
                subarrayCount += remainderFreq[remainder];
            }

            // Increment frequency of current remainder
            remainderFreq[remainder]++;
        }

        return subarrayCount;
    }
};
