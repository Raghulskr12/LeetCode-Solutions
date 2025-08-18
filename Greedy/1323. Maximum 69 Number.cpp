class Solution {
public:
    int maximum69Number(int num) {
        // Convert the number to a string for easy digit manipulation
        string numStr = to_string(num);

        // Traverse the string to find the first occurrence of '6'
        for (int i = 0; i < numStr.size(); i++) {
            if (numStr[i] == '6') {
                // Change the first '6' to '9' to maximize the number
                numStr[i] = '9';
                break; // Only change the first '6'
            }
        }

        // Convert the modified string back to an integer
        int maxNum = stoi(numStr);

        // Return the maximized number
        return maxNum;
    }
};
