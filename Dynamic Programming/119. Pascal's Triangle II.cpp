class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascalRow;  // This will store the elements of the row
        
        // The first element is always 1
        pascalRow.push_back(1);
        
        // Calculate the number of elements in this row (rowIndex+1)
        int elementCount = rowIndex + 1;
        
        // Use a long long to prevent integer overflow during calculations
        long long currentElement = 1;
        
        // Generate each element in the row from index 1 to elementCount-1
        for(int i = 1; i < elementCount; i++) {
            // Calculate binomial coefficient C(rowIndex, i)
            // Using the multiplicative formula:
            // C(n,k) = C(n,k-1) * (n - k + 1) / k
            currentElement = currentElement * (elementCount - i);
            currentElement = currentElement / i;
            
            pascalRow.push_back(currentElement);
        }
        
        return pascalRow;
    }
};