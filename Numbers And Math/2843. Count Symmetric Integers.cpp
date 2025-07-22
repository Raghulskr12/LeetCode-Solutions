class Solution {
public:
    // Helper function to check if a number (as string) is symmetric
    bool isSymmetric(string numberStr) {
        int leftSum = 0;
        int rightSum = 0;

        int left = 0;
        int right = numberStr.size() - 1;

        // If the number has odd length, it cannot be symmetric
        if (numberStr.size() % 2 != 0) return false;

        // Traverse from both ends toward the center
        while (left < right) {
            leftSum += numberStr[left] - '0';   // Add digit on left
            rightSum += numberStr[right] - '0'; // Add digit on right
            left++;
            right--;
        }

        // A number is symmetric if the two halves have equal digit sums
        return leftSum == rightSum;
    }

    // Main function to count symmetric integers in the given range
    int countSymmetricIntegers(int low, int high) {
        int symmetricCount = 0;

        for (int num = low; num <= high; num++) {
            string numberStr = to_string(num); // Convert integer to string
            if (isSymmetric(numberStr)) {
                symmetricCount++; // Count it if it's symmetric
            }
        }

        return symmetricCount;
    }
};
