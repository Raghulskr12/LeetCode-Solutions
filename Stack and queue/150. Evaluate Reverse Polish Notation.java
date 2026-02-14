class Solution {
    public int evalRPN(String[] tokens) {

        Stack<Integer> freq = new Stack<>();

        for (int i = 0; i < tokens.length; i++) {

            // Check operators using string comparison
            if (tokens[i].equals("+")) {

                int two = freq.pop();
                int one = freq.pop();

                freq.push(one + two);
            }
            else if (tokens[i].equals("*")) {

                int two = freq.pop();
                int one = freq.pop();

                freq.push(one * two);
            }
            else if (tokens[i].equals("/")) {

                int two = freq.pop();
                int one = freq.pop();

                freq.push(one / two);
            }
            else if (tokens[i].equals("-")) {

                int two = freq.pop();
                int one = freq.pop();

                freq.push(one - two);
            }
            else {
                // Token is a number → convert string to int
                freq.push(Integer.parseInt(tokens[i]));
            }
        }

        return freq.peek();
    }
}
