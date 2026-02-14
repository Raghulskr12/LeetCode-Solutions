class Solution {

    public String removeStars(String inputString) {

        // Stack to store characters after processing '*'
        Stack<Character> characterStack = new Stack<>();

        // Convert string to char array for easy traversal
        char[] characters = inputString.toCharArray();

        // Traverse each character in the string
        for (int i = 0; i < characters.length; i++) {

            // If current character is '*'
            // Remove the most recent character (top of stack)
            if (characters[i] == '*') {
                characterStack.pop();
            }
            else {
                // Otherwise push the character into stack
                characterStack.push(characters[i]);
            }
        }

        // Build final string from remaining stack characters
        StringBuilder result = new StringBuilder();

        for (char ch : characterStack) {
            result.append(ch);
        }

        // Return processed string
        return result.toString();
    }
}
