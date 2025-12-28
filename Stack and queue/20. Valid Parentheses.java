class Solution {
    public boolean isValid(String s) {

        // Stack to store opening brackets
        Deque<Character> stack = new ArrayDeque<>();

        // Traverse each character in the string
        for (int i = 0; i < s.length(); i++) {

            char currentChar = s.charAt(i);

            // If it's an opening bracket, push it onto the stack
            if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
                stack.push(currentChar);
            } 
            // If it's a closing bracket
            else {

                // If stack is empty, there is no matching opening bracket
                if (stack.isEmpty()) return false;

                // Check for matching pairs
                if (currentChar == ')' && stack.peek() == '(') {
                    stack.pop(); // valid pair found
                } 
                else if (currentChar == '}' && stack.peek() == '{') {
                    stack.pop(); // valid pair found
                } 
                else if (currentChar == ']' && stack.peek() == '[') {
                    stack.pop(); // valid pair found
                } 
                // Mismatched bracket
                else {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets were matched correctly
        return stack.isEmpty();
    }
}
