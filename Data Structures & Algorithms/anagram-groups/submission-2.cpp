class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector<string>> o;
        
        unordered_map <string, pair <int, int>> f;
        for(auto i : strs){
            f[i].first++;
        }

        for(int i = 0; i<strs.size(); i++){
            vector <string> i_temp;
            if(f[strs[i]].second<1){
                i_temp.push_back(strs[i]);
                if(i!=strs.size()-1){
                    for(int j = i+1; j<strs.size() ; j++){
                        unordered_map<char, int> m, p;
                        for(char k:strs[i]){
                            m[k]++;
                        }
                        for(char k:strs[j]){
                            p[k]++;
                        }

                        if(m == p){
                            i_temp.push_back(strs[j]);
                            f[strs[j]].second++;
                        }
                    }
                }
                o.push_back(i_temp);
            }
        }

        return o;
    }
};
