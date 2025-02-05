class Solution {
public:
    int sumOfSquares(vector<int>& arr) {
        int sum = 0;              // Variable to store the sum of squares
        int n = arr.size();       // Size of the array

        // Iterate through the array to check divisors of the array size
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {     // Check if the index is a divisor of the array size
                sum += arr[i - 1] * arr[i - 1];  // Add the square of the element at (i - 1) to the sum
            }
        }

        // Check if the last element is a valid divisor case
        if (n % n == 0) {
            sum += arr[n - 1] * arr[n - 1];  // Add the square of the last element
        }

        return sum;  // Return the total sum of squares
    }
};
