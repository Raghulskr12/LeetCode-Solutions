class Solution {
    public:
        string clearDigits(string s) {
           stack<char> charStack; // Stack to store non-digit characters
           string result = ""; // Stores the final processed string
    
           // Iterate through each character in the string
           for (int i = 0; i < s.size(); i++) {
               if (isalpha(s[i])) { 
                   charStack.push(s[i]); // Push alphabetic characters onto the stack
               } else { 
                   if (!charStack.empty()) {
                       charStack.pop(); // Pop the last stored character when encountering a digit
                   }
               }
           }
    
           // Extract characters from the stack to form the result string
           int stackSize = charStack.size();
           for (int i = 0; i < stackSize; i++) {
               result += charStack.top(); 
               charStack.pop();
           }
    
           // Reverse the result to maintain original order
           reverse(result.begin(), result.end());
    
           return result;
        }
    };
    