class Solution {
public:
    // Function to encrypt a single number
    int encrypt(int num) {
        int encryptedNum = 0;
        int maxDigit = INT_MIN;
        int digitCount = 0;

        // If the number has only one digit, return it as is
        if (num / 10 == 0) return num;

        int tempNum = num;

        // Find the maximum digit and count total digits
        while (tempNum != 0) {
            int digit = tempNum % 10;
            if (digit > maxDigit) maxDigit = digit;
            tempNum /= 10;
            digitCount++;
        }

        // Construct the encrypted number by repeating the maxDigit
        // for the total number of digits in the original number
        while (digitCount != 0) {
            digitCount--;
            encryptedNum += maxDigit * pow(10, digitCount);
        }

        return encryptedNum;
    }

    // Function to compute the sum of encrypted integers
    int sumOfEncryptedInt(vector<int>& nums) {
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Uncomment below line if debugging is needed
            // cout << encrypt(nums[i]) << endl;

            totalSum += encrypt(nums[i]);
        }

        return totalSum;
    }
};
