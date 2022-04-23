class Solution {
    private:
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> longToShort, shortToLong;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
         string shortUrlCode = "";
        if(longToShort.find(longUrl) == longToShort.end()){
            
            // if shortUrlCode generated is duplicate, regenerate it
            do{
                for(int i = 0; i < 6; ++i){
                    int idx = rand()%charset.size();
                    shortUrlCode += charset[idx];
                }
            } while (shortToLong.find(shortUrlCode) != shortToLong.end()) ;
            longToShort[longUrl] = shortUrlCode;
            shortToLong[shortUrlCode] = longUrl;
        }
        else{
            shortUrlCode = longToShort[longUrl];
        }
        return "http://tinyurl.com/" + shortUrlCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() != 25) return "";
        string shortUrlCode = shortUrl.substr(19, 6);
        if(shortToLong.find(shortUrlCode) == shortToLong.end()){
            return ""; // innvalid url
        }
        return shortToLong[shortUrlCode];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));