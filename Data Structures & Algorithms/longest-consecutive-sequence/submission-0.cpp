class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        unordered_map<int, int> m;
        // Note any m value is init 0
        for(int num : nums){
            s.insert(num);
        }

        int max_val = 0;
        for(int num : s){
            int prev_seq = m[num-1];
            int next_seq = m[num+1];
            int val = prev_seq + 1 + next_seq;
            
            m[num] = val;
            // Next should be fine as if number doesn't exist we will have 0 if(prev_seq > 0)
            m[num-m[num-1]] = val;
            m[num+m[num+1]] = val;
            max_val = max(val, max_val);
        }
        // int max_val = 0;
        // for(auto& [val, prev_size] : m){
        //     max_val = max(max_val, prev_size);
        // }
        return max_val;
    }
};
