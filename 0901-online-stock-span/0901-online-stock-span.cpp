

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 //🔑 Core Idea (Intuition)
//For each new price:
//We want to count how many consecutive previous days had prices ≤ today’s price.
//Instead of checking day-by-day (slow), we use a stack that keeps prices in strictly decreasing order.
//Stack stores:
//{price, span}
//Span = how many days this price already covers.

//🚀 Algorithm (Optimized – O(1) amortized)
//When next(price) is called:
//Start span = 1 (today itself)
//While stack is not empty and
//stack.top().price <= price
//Add stack.top().span to span
//Pop the stack
//Push {price, span} into stack
//Return span
//Each element is pushed & popped once only → super efficient.

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}

public:
    StockSpanner() { // Constructor ; Called once when object is created.
    }
    
    int next(int price) { //This function is called every day
        int span = 1; //Minimum span is 1

        // Pop all prices <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; //Add the span of the popped element
            st.pop(); //Remove that day from stack
        }

        st.push({price, span});
        return span; //Return today’s final span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */