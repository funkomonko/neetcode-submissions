class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timeMap; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = timeMap[key].size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(timeMap[key][mid].second == timestamp){
                return timeMap[key][mid].first;
            }
            else if(timeMap[key][mid].second > timestamp){
                r = mid - 1;
            }
            else if(timeMap[key][mid].second < timestamp){
                l = mid + 1;
            }
        }
        if (r >= 0) {
            return timeMap[key][r].first;
        }
        
        return "";
    }
};
