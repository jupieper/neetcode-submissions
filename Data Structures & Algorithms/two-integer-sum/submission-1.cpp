class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m = {};
        for(int i=0; i<nums.size(); i++){
            m.insert({target-nums[i], i});
        }

        for(int i=0; i<nums.size(); i++){
            if(m.contains(nums[i])){
                int j = m[nums[i]];
                if(i == j) {
                    continue;
                }
                vector<int> v;
                if(j < i) v = {j, i};
                else v = {i, j};

                return v;
            }
        }
        
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=0; j<nums.size(); j++){
        //         if(i==j) continue;
        //         if(nums[i] + nums[j] == target){
        //             vector<int> v = {i, j};
        //             return v;
        //         }
        //     }
        // }
    }
};
