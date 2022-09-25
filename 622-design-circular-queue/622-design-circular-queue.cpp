class MyCircularQueue {
public:
    int head=0, tail=0, size=0, arraysize=0;
    vector<int> cq;
    MyCircularQueue(int k) {
        arraysize=k; cq.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(isEmpty())
        {
            head=tail=0;
            cq[tail]=value;
            size++;
            return true;
        }
        tail++;
        tail%=arraysize;
        cq[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % arraysize;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return cq[head];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return cq[tail];
    }
    
    bool isEmpty() {
        if(size==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(size==arraysize)
            return 1;
        return 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */