//
// Created by patrickmanacorda on 8/3/21.
//

class Solution {
    bool contains(tuple<int,int>& a, tuple<int,int>& b){
        return get<0>(a) <= get<0>(b) && get<1>(a) >= get<1>(b);
    }
public:
    vector<int> partitionLabels(string s) {
        map<char, int> start;
        map<char, int> end;

        for(int i=0; i<s.size(); i++){
            if(start.find(s[i]) == start.end()){
                start[s[i]] = i;
                end[s[i]] = i;
            }
            else{
                end[s[i]] = i;
            }
        }
        vector<tuple<int,int>> intervals;
        for(auto key = end.begin(); key != end.end(); key++){
            intervals.push_back(make_pair(start[key->first],end[key->first]));
        }
        sort(intervals.begin(), intervals.end(), [](tuple<int,int>& left, tuple<int,int>& right)-> bool{
            return get<0>(left) == get<0>(right) ? get<1>(left) < get<1>(right) : get<0>(left) < get<0>(right);
        });

        bool valid[intervals.size()];
        memset(valid, false, intervals.size());

        for(int i=intervals.size()-1; i>0; i--){
            for(int j=i-1; j>=0; j--){
                if(contains(intervals[j], intervals[i]))
                    break;
                if(j==0)
                    valid[i] = true;
            }
        }
        vector<int> chunks;
        for(int i=0; i<intervals.size(); i++)
            if(valid[i])
                chunks.push_back(get<1>(intervals[i])-get<0>(intervals[i]));

            return chunks;
    }
};
