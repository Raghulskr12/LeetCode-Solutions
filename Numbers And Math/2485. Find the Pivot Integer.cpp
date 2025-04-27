class Solution {
    public:
        int pivotInteger(int n) {
            if (n == 1) return 1; // Special case: if n is 1, pivot is 1 itself
            
            int leftSum = 1; // Cumulative sum from the start (starting from 1)
            int totalSumExcludingFirst = (n * (n + 1)) / 2 - 1; // Total sum excluding the first element
            int currentNum = 2; // Start checking from number 2
    
            for (int i = 0; i < n; i++) {
                // If left sum == right sum, currentNum is the pivot
                if (leftSum == totalSumExcludingFirst) return currentNum;
    
                // Add the current number to the left sum
                leftSum += currentNum;
    
                // Subtract the current number from the right sum
                totalSumExcludingFirst -= currentNum;
    
                // Move to the next number
                currentNum++;
            }
    
            return -1; // No pivot found
        }
    };
    