//This is not most optimal but it makes human sense to me
public int maxProfit(int k, int[] prices) {
    PriorityQueue<Integer> profits = new PriorityQueue<Integer>(Collections.reverseOrder());
    if(prices.length == 0)
        return 0;
    int buy = prices[0];

    for(int i=1; i<prices.length; i++){
        if(prices[i] < prices[i-1]){
            profits.add(prices[i-1]-buy);
            buy = prices[i];
        }
        if(i+1 == prices.length){
            if(prices[i] >= buy)
                profits.add(prices[i]-buy);
        }
    }


    if(profits.size() >= k){
        int profit = 0;
        int count = 0;
        while(profits.size() != 0 && count != k){
            profit += profits.poll();
            count += 1;
        }
        return profit;
    }else{
        if(profits.size() == 0)
            return 0;
        int profit = 0;
        while(profits.size() != 0)
            profit += profits.poll();
        return profit;
    }
}