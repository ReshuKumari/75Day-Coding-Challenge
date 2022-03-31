class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int sum = 0, maxWindow = 0, window = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            sum += grumpy[i] == 0 ? customers[i] : 0;
            window += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= minutes)
                window -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
            maxWindow = max(maxWindow, window);
        }
        return sum + maxWindow;
    }
};