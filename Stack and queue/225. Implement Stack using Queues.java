import java.util.LinkedList;
import java.util.Queue;

class MyStack {

    // Queue used to simulate stack behavior
    private Queue<Integer> queue = new LinkedList<>();

    // Constructor
    public MyStack() {
        // No initialization needed
    }

    // Push element onto stack
    public void push(int value) {

        // Step 1: Add element to the queue
        queue.add(value);

        // Step 2: Rotate the queue so that
        // the newly added element comes to the front
        int size = queue.size();
        for (int i = 1; i < size; i++) {
            queue.add(queue.remove());
        }
    }

    // Removes and returns the top element of the stack
    public int pop() {
        return queue.remove(); // Front element represents stack top
    }

    // Returns the top element without removing it
    public int top() {
        return queue.peek();
    }

    // Checks whether the stack is empty
    public boolean empty() {
        return queue.isEmpty();
    }
}
