class Solution {
public:
    vector<int> minOperations(string boxes) {
        // Optimized Approach (Two-Pass Solution)
        int leftOnes = 0;       // Number of '1's encountered so far from the left
        int leftTravel = 0;     // Total distance traveled for '1's from the left
        int rightOnes = 0;      // Number of '1's encountered so far from the right
        int rightTravel = 0;    // Total distance traveled for '1's from the right
        vector<int> operations(boxes.size(), 0);  // Array to store the minimum operations for each box

        // First pass: Traverse from left to right
        for (int i = 0; i < boxes.size(); i++) {
            leftTravel += leftOnes;  // Add the total travel distance for '1's on the left
            operations[i] += leftTravel;  // Update the operations for the current box
            if (boxes[i] == '1') {
                leftOnes++;  // Increment the count of '1's
            }
        }

        // Second pass: Traverse from right to left
        for (int i = boxes.size() - 1; i >= 0; i--) {
            rightTravel += rightOnes;  // Add the total travel distance for '1's on the right
            operations[i] += rightTravel;  // Update the operations for the current box
            if (boxes[i] == '1') {
                rightOnes++;  // Increment the count of '1's
            }
        }

        return operations;
    }
};

/*
    Brute Force Approach (Nested Loops)
    - Time Complexity: O(n^2), where n is the size of the string.
    - For each box, calculate the distance to all other boxes containing '1'.
    - This approach is less efficient for larger inputs.
*/
/*
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> operations;  // Array to store the minimum operations for each box
        long long distance = 0;  // Sum of distances to move balls to a specific box

        for (int i = 0; i < boxes.size(); i++) {
            distance = 0;  // Reset distance for each box
            for (int j = 0; j < boxes.size(); j++) {
                if (j == i) continue;  // Skip the same box
                if (boxes[j] == '1') {
                    distance += abs(i - j);  // Add the distance to move '1's
                }
            }
            operations.push_back(distance);  // Store the result
        }
        return operations;
    }
};
*/
