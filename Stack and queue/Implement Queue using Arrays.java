class ArrayQueue {

    // Index pointing to the front element of the queue
    private int frontIndex = 0;

    // Index pointing to the next free position at the rear
    private int rearIndex = 0;

    // Array used to store queue elements
    private int[] queueArray = new int[100];

    // Current number of elements in the queue
    private int currentSize = 0;

    // Default constructor
    public ArrayQueue() {
        // No initialization needed here
    }

    // Adds an element to the rear of the queue
    public void push(int element) {
        queueArray[rearIndex] = element;
        rearIndex++;          // Move rear forward
        currentSize++;        // Increase size
    }

    // Removes and returns the front element of the queue
    public int pop() {
        currentSize--;        // Decrease size
        return queueArray[frontIndex++]; // Return and move front forward
    }

    // Returns the front element without removing it
    public int peek() {
        return queueArray[frontIndex];
    }

    // Checks whether the queue is empty
    public boolean isEmpty() {
        return currentSize == 0;
    }
}
