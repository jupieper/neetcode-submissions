bool comp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> new_intervals;
        vector<int> cur = intervals[0];
        for(size_t i=1; i<intervals.size(); i++){
            if(cur[1] >= intervals[i][0]){
                if(cur[1] > intervals[i][1]){
                    continue;
                }
                cur[1] = intervals[i][1];
            } else {
                new_intervals.push_back(cur);
                cur = intervals[i];
            }
        }
        new_intervals.push_back(cur);
        
        return new_intervals;
    }
};
