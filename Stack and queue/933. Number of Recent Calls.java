class RecentCounter {

    // Queue to store ping timestamps
    private Queue<Integer> requestQueue;

    
    // Constructor
    public RecentCounter() {
        this.requestQueue = new LinkedList<>();
    }
    

    // Process a new ping
    public int ping(int currentTime) {

        // Add current request
        requestQueue.offer(currentTime);

        // Remove requests older than (t - 3000)
        while (!requestQueue.isEmpty() &&
               requestQueue.peek() < currentTime - 3000) {

            requestQueue.poll();
        }

        // Remaining queue size = valid requests
        return requestQueue.size();
    }
}
