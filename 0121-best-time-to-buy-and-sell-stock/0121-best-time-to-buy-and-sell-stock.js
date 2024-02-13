/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let min_price = prices[0];
    let max_profit = 0;
    
    for(let i = 1; i < prices.length; i++){
        max_profit = Math.max(max_profit, (prices[i]-min_price));
        min_price = Math.min(min_price,prices[i]);
    }
    
    return max_profit;
};


/**
 * @param {number[]} prices
 * @return {number})
 */
// var maxProfit = function(prices) {
//     let profit = 0;
//     for(let i = 0; i < prices.length; i++){
//         for(let j = i+1; j < prices.length;j++){
            
//             let new_profit = prices[j] - prices[i];
            
//             if(new_profit>profit){
//                 profit = new_profit;
//             }
//         }
//     }
    
//     return profit;
// };