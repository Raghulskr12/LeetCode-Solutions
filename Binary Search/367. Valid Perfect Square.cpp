class Solution {
    public:
        bool isPerfectSquare(int num) {
            long long low = 1, high = num; // Use long long to avoid overflow
    
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                long long square = mid * mid; // Compute square of mid
    
                if (square == num) return true; // Found perfect square
                if (square < num) 
                    low = mid + 1;  // Increase lower bound
                else 
                    high = mid - 1; // Decrease upper bound
            }
    
            return false; // Not a perfect square
        }
    };
    