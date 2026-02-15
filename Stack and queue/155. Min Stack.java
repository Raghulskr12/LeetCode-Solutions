class MinStack {

    // Stack stores pair:
    // [0] → actual value
    // [1] → minimum value at this stack level
    private Stack<int[]> stack;

    // Constructor → initialize stack
    public MinStack() {
        this.stack = new Stack<>();
    }

    
    // Push a value into stack
    public void push(int value) {

        // If stack is empty → value itself is minimum
        if (stack.isEmpty()) {
            stack.push(new int[]{value, value});
        }
        else {
            // Current minimum so far
            int currentMin = stack.peek()[1];

            // New minimum after push
            int newMin = Math.min(value, currentMin);

            stack.push(new int[]{value, newMin});
        }
    }

    
    // Remove top element
    public void pop() {
        stack.pop();
    }

    
    // Return top element value
    public int top() {
        return stack.peek()[0];
    }

    
    // Return minimum element in stack
    public int getMin() {
        return stack.peek()[1];
    }
}
