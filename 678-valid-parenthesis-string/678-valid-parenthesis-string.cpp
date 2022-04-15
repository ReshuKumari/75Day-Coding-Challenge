class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        //if(n&1) return false;
        int balance = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '*' || s[i] == '(') balance++;   
            else balance--; 
            if(balance < 0) return false;
        }
        //if(abs(balance)%2 != 0) return false;
        balance = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '*' || s[i] == ')') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        // if(abs(balance)%2 != 0) return false;
        return true;
    }
};