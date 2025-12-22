/**
 * ArrayStack
 * -----------
 * A simple stack implementation using an array.
 * Follows LIFO (Last In, First Out) principle.
 */
class ArrayStack {

    // Maximum size of the stack
    private static final int MAX_SIZE = 100;

    // Array to store stack elements
    private int[] stackArray = new int[MAX_SIZE];

    // Index of the top element in the stack
    // -1 indicates that the stack is empty
    private int topIndex = -1;

    // Default constructor
    public ArrayStack() {
        // Stack is initialized as empty
    }

    /**
     * Pushes an element onto the stack
     * @param value element to be added
     */
    public void push(int value) {
        // Increment top index and insert the element
        topIndex++;
        stackArray[topIndex] = value;
    }

    /**
     * Removes and returns the top element of the stack
     * @return top element
     */
    public int pop() {
        // Return the top element and decrease top index
        return stackArray[topIndex--];
    }

    /**
     * Returns the top element without removing it
     * @return top element
     */
    public int peek() {
        return stackArray[topIndex];
    }

    /**
     * Checks whether the stack is empty
     * @return true if stack is empty, otherwise false
     */
    public boolean isEmpty() {
        return topIndex == -1;
    }
}
