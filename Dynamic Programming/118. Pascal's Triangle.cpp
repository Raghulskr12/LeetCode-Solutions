class Solution {
public:
    // Helper function to compute the nth row of Pascal's Triangle
    vector<int> computePascalRow(int rowNum) {
        vector<int> currentRow;
        currentRow.push_back(1); // The first element is always 1
        
        int element = 1; // Initialize the first element of the row
        
        // Compute the rest of the elements in the row
        for (int i = 1; i < rowNum; i++) {
            // The next element is computed using the previous element:
            // element = element * (rowNum - i) / i
            element = element * (rowNum - i) / i;
            currentRow.push_back(element);
        }
        
        return currentRow;
    }

    // Function to generate Pascal's Triangle up to 'numRows' rows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        
        // Generate each row one by one
        for (int i = 1; i <= numRows; i++) {
            pascalTriangle.push_back(computePascalRow(i));
        }
        
        return pascalTriangle;
    }
};