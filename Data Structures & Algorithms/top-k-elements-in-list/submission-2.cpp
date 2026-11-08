class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(size_t i=0;i<nums.size();i++){
            m[nums[i]]+=1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> p;
        for(auto& [num, cnt] : m){
            p.push({cnt, num});
            if(p.size()>k) p.pop();
        }


        vector<int> res;
        while(!p.empty()){
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};
