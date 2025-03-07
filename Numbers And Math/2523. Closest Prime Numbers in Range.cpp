class Solution {
    public:
        // Function to check if a number is prime
        bool isPrime(int num) {
            if (num <= 1) return false; // Numbers <= 1 are not prime
            int limit = sqrt(num); // Check divisibility up to sqrt(num)
            for (int divisor = 2; divisor <= limit; divisor++) {
                if (num % divisor == 0) return false; // If divisible, it's not prime
            }
            return true;
        }
    
        vector<int> closestPrimes(int left, int right) {
            vector<int> primeNumbers; // Stores all prime numbers in the given range
    
            // Find all prime numbers in the range [left, right]
            for (int num = left; num <= right; num++) {
                if (isPrime(num)) primeNumbers.push_back(num);
            }
    
            vector<int> result(2, -1); // Stores the closest prime pair {prime1, prime2}
            int minDifference = INT_MAX; // Tracks the smallest difference between two primes
    
            // If there are fewer than 2 primes, return {-1, -1}
            if (primeNumbers.size() < 2) return result;
    
            // Find the closest prime pair
            for (int i = 0; i < primeNumbers.size() - 1; i++) {
                int difference = primeNumbers[i + 1] - primeNumbers[i];
                if (difference < minDifference) {
                    minDifference = difference;
                    result[0] = primeNumbers[i];
                    result[1] = primeNumbers[i + 1];
                }
            }
    
            return result;
        }
    };
    