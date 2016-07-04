class MinStack {
    stack<int> s;
    stack<int> trackMin;
public:
    void push(int x) {
        if(trackMin.empty() || x<=trackMin.top())
            trackMin.push(x);
        s.push(x);
    }

    void pop() {
        if(s.empty()) return;
        if(s.top()==trackMin.top())
            trackMin.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return trackMin.top();
    }
};
