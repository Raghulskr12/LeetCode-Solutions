class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        // If n is odd, include 0 to make the total sum zero
        if (n % 2 != 0) {
            result.push_back(0);
        }

        // Add pairs of positive and negative integers
        for (int num = 1; num <= n; num++) {
            // Stop if we've reached the required count
            if (result.size() == n) break;

            result.push_back(num);       // Add positive number
            result.push_back(-num);      // Add corresponding negative number
        }

        return result;
    }
};
