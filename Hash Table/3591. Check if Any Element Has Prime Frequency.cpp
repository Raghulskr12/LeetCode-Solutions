class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int number) {
        if (number == 0 || number == 1) return false;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    // Function to check if any number in the array has a prime frequency
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        // Count the frequency of each number in the array
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Check if any frequency is a prime number
        for (const auto& entry : frequencyMap) {
            if (isPrime(entry.second)) return true;
        }

        return false; // No prime frequency found
    }
};
