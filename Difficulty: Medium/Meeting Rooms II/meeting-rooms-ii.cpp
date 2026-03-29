class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        map<int, int> mp;
        int n= start.size();
        for(int i = 0; i<n; i++){
            mp[start[i]]++;
            mp[end[i]]--;
        }
        
        int overlaps = 0, maxOverlap = 0;
        for(auto &it : mp){
            overlaps += it.second;
            
            if(overlaps > maxOverlap){
                maxOverlap = overlaps;
            }
        }
        return maxOverlap;
        
    }
};
