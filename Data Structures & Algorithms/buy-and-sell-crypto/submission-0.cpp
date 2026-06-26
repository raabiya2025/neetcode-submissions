class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,profit;
        int left=0,right=1;
        while(right<prices.size())
        {
            if(prices[left]<prices[right]){
                profit=prices[right]-prices[left];
                if(profit>maxprofit){
                    maxprofit=profit;
                }
                
                
            }
            else{
                left=right;
            }
            right++;
        }
        return maxprofit;


        
    }
};
Best Time to Buy and Sell Stock
Pattern
Sliding Window / Two Pointers

Key Observation
We must buy before we sell.
For every selling day, we want the minimum buying price seen so far.
If we find a cheaper price, it becomes our new buying day.

    
Pointer Meaning
left  = buying day
right = selling day


Invariant:
left < right
We always buy before selling.



Core Logic

For each right:
Profitable Transaction
prices[right] > prices[left]

Profit:
prices[right] - prices[left]


Update:
maxprofit = max(maxprofit, profit);
Better Buying Day Found
prices[right] <= prices[left]

Current buy day is useless.

Update:
left = right;

Reason:
A cheaper stock price gives better profit
for all future selling days.
Why left = right?

Example:

[10, 1, 5, 6, 7]

At:

L    R
10   1

Buying at:

10

can never be better than buying at:

1

Therefore:

left = right;
Dry Run
prices = [10,1,5,6,7,1]
Start
L=10
R=1

Not profitable.

left = right;
Next
L=1
R=5

Profit:

5 - 1 = 4
Next
L=1
R=6

Profit:

6 - 1 = 5
Next
L=1
R=7

Profit:

7 - 1 = 6

Maximum profit:

6
Edge Cases
Strictly Decreasing Prices
[10,8,7,5,2]

No profitable transaction.

Output:

0
Single Element
[5]

Cannot buy and sell.

Output:

0
All Equal Prices
[5,5,5,5]

Profit:

0
Minimum Price at End
[7,6,5,1]

No future day exists after buying at 1.

Output:

0
Common Mistakes
1. Reversing Profit Formula

Wrong:

profit = prices[left] - prices[right];

Correct:

profit = prices[right] - prices[left];

Remember:

Sell Price - Buy Price
2. Returning profit

Wrong:

return profit;

Returns last calculated profit.

Correct:

return maxprofit;
3. Incrementing Left

Wrong:

left++;

Correct:

left = right;

Because we want the newly found minimum price.

4. Using Nested Loops

Brute Force:

for(i)
   for(j)

Complexity:

O(n²)

Will pass small inputs but is inefficient.

Complexity
Time
O(n)

Reason:

right traverses array once.
left only moves forward.

Each element is processed at most once.

Space
O(1)

Only a few variables are used.

Interview Explanation (30 Seconds)

Use two pointers where left represents the buying day and right represents the selling day.
If the selling price is greater than the buying price, calculate profit and update the maximum profit. 
Otherwise, move left to right because we've found a cheaper buying day. 
Traverse the array once, giving O(n) time and O(1) space.
