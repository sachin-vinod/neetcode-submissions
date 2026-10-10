class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push({val,val});
        }
        else{
            int mi=min(val,st.top().second);
            st.push({val,mi});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
