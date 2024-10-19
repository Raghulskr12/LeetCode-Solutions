class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIndex = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                chIndex = i;
                break;
            }
        }
        
        int left = 0;
        int right = chIndex;
        while (left < right) {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left++;
            right--;
        }
        
        return word;
    }
};

/*
Explanation:
- The function `reversePrefix` takes a string `word` and a character `ch` as inputs.
- It first finds the index of the first occurrence of `ch` in `word`.
- It then uses two pointers, `left` and `right`, to reverse the substring from the start of `word` up to the index of `ch`.
- The characters at the `left` and `right` pointers are swapped until the pointers meet or cross.
- Finally, it returns the modified `word` with the prefix reversed.
*/
