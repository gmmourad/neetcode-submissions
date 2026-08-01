class MinStack {
public:
    MinStack() {       
    }
    
    void push(int val) {
        if (s1.empty())
        {
            s1.push(0);
            min = static_cast<long>(val);
        }
        else
        {
            s1.push(static_cast<long>(val)-min);
            if (val < min)
            {
                min = val;
            }
        }
    }
    
    void pop() {
        long pop_val = s1.top();
        if (pop_val < 0)
        {
            min = min - pop_val; 
        }
        s1.pop();
    }
    
    int top() {
        long pop_val = s1.top();
        if (pop_val <= 0)
        {
            return static_cast<int>(min);
        }
        else
        {
            return static_cast<int>(pop_val + min);
        }
    }
    
    int getMin() {
        return min;
    }
private:
    long min = {};
    std::stack<long> s1{};
};
