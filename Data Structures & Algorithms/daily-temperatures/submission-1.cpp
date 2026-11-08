class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size());
        s.push(0);
        for(int i=1; i<temperatures.size(); i++){
            int index = s.top();
            while(temperatures[index] < temperatures[i]){
                res[index] = i-index;
                s.pop();
                if(s.empty()) break;
                index = s.top();
            }

            s.push(i);
        }

        return res;
    }
};
