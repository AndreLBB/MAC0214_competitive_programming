// https://leetcode.com/problems/online-stock-span
class StockSpanner {
public:
    stack<pair<int,int>> s;
    int count = 0;
    StockSpanner() {
        s.push({INT_MAX,0});
    }
    
    int next(int price) {
        while (s.top().first <= price) s.pop();
        auto topo = s.top();
        count++;
        s.push({price,count});
        return count - topo.second; 
    }
};

// Basicamente temos que implementar um nearest bigger element

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */