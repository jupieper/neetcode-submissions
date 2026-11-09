struct Higher {
    bool operator()(const pair<double, vector<int>>& a, const pair<double, vector<int>>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, Higher> p;

        for(vector<int> point : points){
            double res = std::sqrt(std::pow(point[0], 2) + std::pow(point[1], 2));

            p.push({res, point});
        }

        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            res.push_back(p.top().second);
            p.pop();
        }

        return res;
    }
};
