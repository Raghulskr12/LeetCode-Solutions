class MyQueue {

    // Primary stack: top of this stack represents the front of the queue
    Deque<Integer> s1 = new ArrayDeque<>();

    // Helper stack used during push operation
    Deque<Integer> s2 = new ArrayDeque<>();

    // Constructor (no reassignment needed)
    public MyQueue() {
        // stacks are already initialized
    }
    
    // Push element x to the back of queue
    public void push(int x) {

        // Move all elements from s1 to s2
        // This reverses the order temporarily
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }

        // Push new element into empty s1
        s1.push(x);

        // Move everything back to s1
        // Now the oldest element stays on top
        while (!s2.isEmpty()) {
            s1.push(s2.pop());
        }
    }
    
    // Removes and returns the front element of the queue
    public int pop() {
        return s1.pop();
    }
    
    // Returns the front element without removing it
    public int peek() {
        return s1.peek();
    }
    
    // Returns true if the queue is empty
    public boolean empty() {
        return s1.isEmpty();
    }
}
