class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> p;
        for(int i : stones){
            p.push(i);
        }

        while(p.size() > 1){
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();

            if(x > y){
                p.push(x-y);
            }
        }

        if(p.empty()){
            return 0;
        } else {
            return p.top();
        }
    }
};
