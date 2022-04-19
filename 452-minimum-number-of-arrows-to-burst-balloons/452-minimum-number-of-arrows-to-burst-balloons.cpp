class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows=0, i=0, n=points.size();
        sort(points.begin(), points.end(), [](auto& a, auto &b){
            return a[1]<b[1];
        });
        while(i<n)
        {
            arrows++;
            int p=points[i++][1];
            while(i<n && points[i][0]<=p)
            {
                i++;
            }
        }
        return arrows;
        /*int arrows = 0, i = 0, n = points.size();
        sort(points.begin(), points.end(), [](auto& a, auto& b){return a[1] < b[1];});
        while (i < n) {
            arrows++;
            int p = points[i++][1];
            while (i < n && points[i][0] <= p) {
                i++;
            }
        }
        return arrows;*/
    }
};