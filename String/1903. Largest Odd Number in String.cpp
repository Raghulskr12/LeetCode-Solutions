class Solution {
    public:
        string largestOddNumber(string num) {
            // Traverse from the end to find the rightmost odd digit
            for (int i = num.size() - 1; i >= 0; i--) {
                if ((num[i] - '0') % 2 != 0) {  
                    return num.substr(0, i + 1);  // Return substring from 0 to i (largest odd number)
                }
            }
            return "";  // If no odd digit is found, return an empty string
    
            /*
            Second approach (alternative but less efficient):
            
            string ans = "";
            int flag = 0;
            
            // Iterate from the last digit to find the first odd number
            for (int i = num.size() - 1; i >= 0; i--) {
                if ((num[i] - '0') % 2 == 0) {
                    continue;  // Skip even digits
                } else {
                    flag = -1;  // Mark that we found an odd digit
                    ans += num[i];  // Append the odd digit
                }
            }
            
            reverse(ans.begin(), ans.end());  // Reverse to maintain order
            return ans;
            */
        }
    };
    