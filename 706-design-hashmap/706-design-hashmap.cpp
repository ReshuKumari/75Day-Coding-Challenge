class MyHashMap {
public:
    vector<pair<int, int>> v;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i].first==key)
            {
                v[i].second=value;
                return;
            }
        }
        v.push_back({key, value});
    }
    
    int get(int key) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i].first==key)
            {
                return v[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int it=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==key)
            {
                it=i;
                break;
            }
        }
        if(it!=-1)
        {
            v.erase(v.begin()+it);
            return;
        }
        else
        {
            return;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */