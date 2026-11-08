class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string str : strs){
            string copy = str;
            sort(str.begin(), str.end());
            m[str].push_back(copy);
        }
        vector<vector<string>> res;
        for(auto& [key, vec]: m){
            res.push_back(vec);
        }
        return res;
    }
};
