class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<pair<int, int>> cars;
            double currentFleetTime = 0;
            int fleets = 0;
    
            for(int i = 0; i < position.size(); ++i){
                pair<int, int> car = {position[i], speed[i]};
                cars.push_back(car);
            }
    
            std::sort(cars.begin(), cars.end(), std::greater<pair<int, int>>()); 
    
            for(int i = 0; i < cars.size(); ++i){
                double time = static_cast<double>(target - cars[i].first) / cars[i].second;
                
                if(time > currentFleetTime){
                    currentFleetTime = time;
                    ++fleets;
                }
            }
    
            return fleets;
        }
    };