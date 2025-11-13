class Solution {
    public int countOperations(int a, int b) {

        // Operation count
        int operations = 0;

        // If any number is zero → no subtraction can occur
        if (a == 0 || b == 0) return 0;

        // If both numbers are equal → only one subtraction needed
        if (a == b) return 1;

        // Keep subtracting the smaller number from the larger one
        while (true) {

            if (a >= b) {
                // Subtract b from a
                a = a - b;
            } else {
                // Subtract a from b
                b = b - a;
            }

            // Count the operation
            operations++;

            // If either number becomes zero → stop
            if (a == 0 || b == 0) break;
        }

        return operations;
    }
}
