vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    vector<int> ans;

    for(auto &value : asteroids){
        while(!st.empty() && value < 0 && st.top() > 0){
            int diff = st.top() + value;

            if(diff < 0){
                st.pop();
            }
            else if(diff > 0)
                value = 0;
            else{
                value = 0;
                st.pop();
            }
        }

        if(value != 0)
            st.push(value);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    if(!ans.empty())    reverse(ans.begin(), ans.end());

    return ans;
}
