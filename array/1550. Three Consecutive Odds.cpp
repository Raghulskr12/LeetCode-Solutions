class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& numbers) {
        // If there are fewer than 3 elements, we can't have three consecutive odd numbers
        if (numbers.size() < 3) return false;

        // Loop through the array up to the third last element
        for (int i = 0; i < numbers.size() - 2; i++) {
            // Check if current and next two elements are all odd
            if (numbers[i] % 2 != 0 && numbers[i + 1] % 2 != 0 && numbers[i + 2] % 2 != 0) {
                return true; // Found three consecutive odd numbers
            }
        }

        // No three consecutive odd numbers found
        return false;
    }
};
