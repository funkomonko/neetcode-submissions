class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <double> fleet;
        vector <pair<int,int>> cars;
        int n = speed.size();
        for(int i = 0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        
        for(int i = 0; i<n; i++){
            double t =(double) (target - cars[i].first)/(cars[i].second);
            if(!fleet.empty() && fleet.top()<t){
                fleet.push(t);
            }
            else if(fleet.empty()){
                fleet.push(t);
            }
        }

        return fleet.size();
    }
};
