class StockSpanner {
    
    Stack<int[]> freq;

    public StockSpanner() {
        this.freq = new Stack<>();
    }
    
    public int next(int price) {

        int span = 1;

        while (!freq.isEmpty() && freq.peek()[0] <= price) {
            span += freq.pop()[1];
        }

        freq.push(new int[]{price, span});

        return span;
    }
}
