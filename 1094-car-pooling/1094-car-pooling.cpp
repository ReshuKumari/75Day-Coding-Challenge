class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*sort(trips.begin(), trips.end(), [](auto lhs,auto rhs){
            return lhs[1]<rhs[1] || (lhs[1]==rhs[1] && lhs[2]<rhs[2]);
        });
        int cap=trips[0][0], prev=trips[0][2];
        if(cap>capacity)
            return false;
        for(int i=1;i<trips.size();i++)
        {
            if(trips[i][1]>=prev)
            {
                cap=trips[i][0];
            }
            else
            {
                int x=cap;
                if(cap+trips[i][0]>capacity)
                {
                    return false;
                }
                cap-=x;
            }
            prev=trips[i][2];
            
        }
        return true;*/
        map<int, int> sortedmap;
        for (int i = 0; i < trips.size(); ++i)
        {
             sortedmap[trips[i][1]] += trips[i][0];
             sortedmap[trips[i][2]] -= trips[i][0];
        }
        for (auto it = sortedmap.begin(); it != sortedmap.end();it++) 
        { 
            capacity -= it->second;
            if (capacity < 0) return false;
        }
        return true;
    }
};