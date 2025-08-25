class Solution {
    public char findTheDifference(String s, String t) {
        // XOR accumulator (will hold the final "extra" character)
        int xorValue = 0;

        // XOR all characters from both strings (except the last extra one in t)
        for (int i = 0; i < s.length(); i++) {
            xorValue ^= s.charAt(i); // XOR with character from s
            xorValue ^= t.charAt(i); // XOR with corresponding character from t
        }

        // XOR with the last extra character in t
        xorValue ^= t.charAt(t.length() - 1);

        // Convert back to char → this is the extra character
        return (char) xorValue;
    }
}
