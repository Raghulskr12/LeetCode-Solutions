class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int total=0;
        total+=numBottles;
        int newbot=0;
        while(numBottles>=numExchange)
        {
            newbot=numBottles/numExchange;
            total+= newbot;
            numBottles =newbot+(numBottles % numExchange);

        }
        return total;
    }
}