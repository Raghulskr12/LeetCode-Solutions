class Solution {
public:
    bool squareIsWhite(string c) {
        if (c[0] == 'a' || c[0] == 'c' || c[0] == 'e' || c[0] == 'g') {
            if (c[1] % 2 == 0) {
                return true;
            } else {
                return false;
            }
        }
        if (c[0] == 'b' || c[0] == 'd' || c[0] == 'f' || c[0] == 'h') {
            if (c[1] % 2 != 0) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

// ⚡ Instant 0ms Solution: Check Chessboard Square Color with Precision! 🎯

/*
Intuition:
The chessboard alternates colors between black and white. If a square is at an odd-indexed column ('a', 'c', 'e', 'g'), it will be white if the row number is even. Conversely, if a square is at an even-indexed column ('b', 'd', 'f', 'h'), it will be white if the row number is odd.

Approach:
1. The first character of the input string represents the column ('a' to 'h'), and the second character represents the row number.
2. For columns 'a', 'c', 'e', 'g', the square is white if the row number (c[1]) is even.
3. For columns 'b', 'd', 'f', 'h', the square is white if the row number (c[1]) is odd.
4. We simply check these conditions and return `true` if the square is white, otherwise `false`.

Time complexity: O(1), since we are performing constant-time checks and comparisons.
Space complexity: O(1), no additional space is used aside from a few variables.
*/
