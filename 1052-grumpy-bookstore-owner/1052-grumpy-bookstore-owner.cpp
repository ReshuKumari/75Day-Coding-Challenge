class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        /*int sum = 0, maxWindow = 0, window = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            sum += grumpy[i] == 0 ? customers[i] : 0;
            window += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= minutes)
                window -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
            maxWindow = max(maxWindow, window);
        }
        return sum + maxWindow;*/
        int sum = 0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }
        
        int maxSum = sum;
        for(int i=0;i<minutes;i++){
            if(grumpy[i] == 1){
                sum += customers[i];
            }
        }
        if(sum > maxSum){
            maxSum = sum;
        }
        int j = minutes;
        int i=0;
        while(j < customers.size()){
            if(grumpy[j] == 1){
                sum += customers[j];
            }
            if(grumpy[i] == 1){
                sum -= customers[i];
            }
            if(sum > maxSum){
                maxSum = sum;
            }
            j++;
            i++;
        }
        return maxSum;
    }
};