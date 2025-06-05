class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Maps to store which characters belong to which row of the keyboard
        unordered_map<char, int> row1Keys;
        unordered_map<char, int> row2Keys;
        unordered_map<char, int> row3Keys;

        // Result vector to store valid words
        vector<string> validWords;

        // Initializing row1: QWERTYUIOP
        row1Keys['q']++; row1Keys['Q']++;
        row1Keys['w']++; row1Keys['W']++;
        row1Keys['e']++; row1Keys['E']++;
        row1Keys['r']++; row1Keys['R']++;
        row1Keys['t']++; row1Keys['T']++;
        row1Keys['y']++; row1Keys['Y']++;
        row1Keys['u']++; row1Keys['U']++;
        row1Keys['i']++; row1Keys['I']++;
        row1Keys['o']++; row1Keys['O']++;
        row1Keys['p']++; row1Keys['P']++;

        // Initializing row2: ASDFGHJKL
        row2Keys['a']++; row2Keys['A']++;
        row2Keys['s']++; row2Keys['S']++;
        row2Keys['d']++; row2Keys['D']++;
        row2Keys['f']++; row2Keys['F']++;
        row2Keys['g']++; row2Keys['G']++;
        row2Keys['h']++; row2Keys['H']++;
        row2Keys['j']++; row2Keys['J']++;
        row2Keys['k']++; row2Keys['K']++;
        row2Keys['l']++; row2Keys['L']++;

        // Initializing row3: ZXCVBNM
        row3Keys['z']++; row3Keys['Z']++;
        row3Keys['x']++; row3Keys['X']++;
        row3Keys['c']++; row3Keys['C']++;
        row3Keys['v']++; row3Keys['V']++;
        row3Keys['b']++; row3Keys['B']++;
        row3Keys['n']++; row3Keys['N']++;
        row3Keys['m']++; row3Keys['M']++;

        // Check each word in the input
        for (int i = 0; i < words.size(); i++) {
            bool isRow1Valid = true;
            bool isRow2Valid = true;
            bool isRow3Valid = true;

            // Check if word can be typed using only row1 keys
            if (row1Keys[words[i][0]] > 0) {
                for (int j = 1; j < words[i].size(); j++) {
                    if (row1Keys[words[i][j]] < 1) {
                        isRow1Valid = false;
                        break;
                    }
                }
                if (isRow1Valid) validWords.push_back(words[i]);
            }

            // Check if word can be typed using only row2 keys
            else if (row2Keys[words[i][0]] > 0) {
                for (int j = 1; j < words[i].size(); j++) {
                    if (row2Keys[words[i][j]] < 1) {
                        isRow2Valid = false;
                        break;
                    }
                }
                if (isRow2Valid) validWords.push_back(words[i]);
            }

            // Check if word can be typed using only row3 keys
            else if (row3Keys[words[i][0]] > 0) {
                for (int j = 1; j < words[i].size(); j++) {
                    if (row3Keys[words[i][j]] < 1) {
                        isRow3Valid = false;
                        break;
                    }
                }
                if (isRow3Valid) validWords.push_back(words[i]);
            }
        }

        return validWords;
    }
};
