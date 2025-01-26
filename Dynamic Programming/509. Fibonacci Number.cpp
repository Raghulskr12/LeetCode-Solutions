class Solution {
public:
    int fibonacci(int n) { 
        // Base case: If the input number is 0, the Fibonacci number is 0
        if(n == 0) return 0;
        // Base case: If the input number is 1, the Fibonacci number is 1
        if(n == 1) return 1;
        // Recursive case: Calculate the Fibonacci number as the sum of the 
        // previous two Fibonacci numbers
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};
