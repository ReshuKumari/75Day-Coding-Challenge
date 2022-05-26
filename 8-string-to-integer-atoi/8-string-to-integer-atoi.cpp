class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, base = 0, i = 0;
        while (s[i] == ' ') { i++; }
        if (s[i] == '-' || s[i] == '+') {
            sign = 1 - 2 * (s[i++] == '-'); 
        }
        while (s[i] >= '0' && s[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (s[i++] - '0');
        }
        return base * sign;
    }
    
    /*int myAtoi(string str) {
    int ret = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
    if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
    while (isdigit(str[i])) {
        if (ret > base || (ret == base && str[i] - '0' > 7)) 
            return sign > 0 ? INT_MAX : INT_MIN;
        ret = 10 * ret + (str[i++] - '0');
    }
    return sign * ret;
}*/
};