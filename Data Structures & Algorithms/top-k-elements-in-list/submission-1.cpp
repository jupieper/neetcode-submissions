class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = m[nums[i]] + 1;
        }

        priority_queue<tuple<int,int>, vector<tuple<int,int>>> p;
        for(auto& [key, cnt] : m){
            p.push({cnt, key});
        }


        vector<int> v = {};
        for(int i=0; i<k; i++){
            v.push_back(get<1>(p.top()));
            p.pop();
        }

        return v;
    }
};
