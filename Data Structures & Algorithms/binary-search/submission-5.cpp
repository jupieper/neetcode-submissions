class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t pos = nums.size()/2;
        size_t bot = 0;
        size_t top = nums.size()-1;

        while(top-bot>1){
            if(target==nums[pos]) {
                return pos;
            } else if(target<nums[pos]){
                top = pos;
            } else {
                bot = pos;
            } 
            pos = (top + bot)/2;
        }

        if(target==nums[top]){
            return top;
        } else if (target==nums[bot]){
            return bot;
        }
        
        return -1;
    }
};
