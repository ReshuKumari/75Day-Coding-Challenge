class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)
            return 0;
        sort(tokens.begin(), tokens.end());
        int ans=0;
        if(tokens[0]<=power && tokens.size()==1)
        {    
            return ans+1;
        }
        else
        {
            int i=0, j=tokens.size()-1;
        
            while(i<=j)
            {
                while(tokens[i]<=power && i<tokens.size())
                {
                    power-=tokens[i++];
                    ans++;
                }
                if(ans>=1 && j-i>1)
                {
                    ans--;
                    power+=tokens[j--];
                }
                else
                {
                    break;
                }
            }
        }
        
        return ans;
    }
};