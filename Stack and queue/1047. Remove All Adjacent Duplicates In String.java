class Solution {

    public String removeDuplicates(String inputString) {

        // Stack to store characters after removing adjacent duplicates
        Stack<Character> characterStack = new Stack<>();

        // Convert string to char array for easy traversal
        char[] characters = inputString.toCharArray();

        // Traverse each character in the string
        for (int i = 0; i < characters.length; i++) {

            // If stack is not empty AND
            // top character is same as current character
            // → duplicate found → remove it
            if (!characterStack.isEmpty() &&
                characterStack.peek() == characters[i]) {

                characterStack.pop();   // Remove duplicate pair
            }
            else {
                // Otherwise push current character
                characterStack.push(characters[i]);
            }
        }

        // Build final string from stack
        StringBuilder result = new StringBuilder();

        for (char ch : characterStack) {
            result.append(ch);
        }

        // Return result string
        return result.toString();
    }
}
