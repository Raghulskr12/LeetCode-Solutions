class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        
        // Initialize counters and candidates for the two possible majority elements
        int countCandidate1 = 0;
        int countCandidate2 = 0;
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;

        // First pass: Find up to two potential majority elements using Boyer-Moore voting algorithm
        for (int i = 0; i < nums.size(); i++) {
            if (countCandidate1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                countCandidate1 = 1;
            }
            else if (countCandidate2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                countCandidate2 = 1;
            }
            else if (nums[i] == candidate1) {
                countCandidate1++;
            }
            else if (nums[i] == candidate2) {
                countCandidate2++;
            }
            else {
                countCandidate1--;
                countCandidate2--;
            }
        }

        // Reset counters to count actual occurrences of candidate1 and candidate2
        countCandidate1 = 0;
        countCandidate2 = 0;

        // Count the frequency of both candidates in the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) countCandidate1++;
            if (nums[i] == candidate2) countCandidate2++;
        }

        // If count is greater than floor(n/3), add to result
        int threshold = nums.size() / 3;
        if (countCandidate1 > threshold) result.push_back(candidate1);
        if (countCandidate2 > threshold) result.push_back(candidate2);

        // Debug output (optional)
        cout << countCandidate1;
        cout << countCandidate2;

        return result;
    }
};
