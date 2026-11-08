struct CompareByTime{
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        return a.first < b.first;
    }
};


class TimeMap {
public:
    unordered_map<string, set<pair<int,string>, CompareByTime>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        auto& timestamp_set = m[key];
        timestamp_set.insert({timestamp, value});
        // m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.contains(key) && !m[key].empty()){
            auto& timestamp_set = m[key];
            auto it = m[key].upper_bound({timestamp, ""});

            if(it == timestamp_set.begin()){
                return "";
            }
            it--;
            return it->second;
        }
        return "";
    }
};
