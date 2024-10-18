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
