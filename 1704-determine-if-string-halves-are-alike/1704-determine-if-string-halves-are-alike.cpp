class Solution {
public:
    bool isvowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' ||
          a=='A' || a=='E' || a=='I' || a=='O' || a=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int c1=0, c2=0;
        int n=s.size();
        for(int i=0, j=n/2;j<n;i++, j++)
        {
            if(isvowel(s[i]))
                c1++;
            if(isvowel(s[j]))
                c2++;
        }
        if(c1==c2)
            return true;
        return false;
    }
};