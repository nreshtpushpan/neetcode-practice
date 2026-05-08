class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

public:

    ListNode * cq = NULL;
    ListNode * head = NULL;
    int curSize, maxSize;

    MyCircularQueue(int k) {
        maxSize = k;
        curSize = 0;
    }
    
    bool enQueue(int value) {
        if(curSize == maxSize) return false;
        ListNode * nextNode = new ListNode(value);
        if(curSize == 0) {
            cq = nextNode;
            head = cq;
        } else {
            cq->next = nextNode;
            cq = cq->next;
        }
        ++curSize;
        return true;
    }
    
    bool deQueue() {
        if(curSize == 0) return false;
        auto nodeDel = head;
        head = head->next;
        delete nodeDel;
        if(--curSize == 0) cq = nullptr;
        return true;
    }
    
    int Front() {
        if(curSize) return head->val;
        return -1;
    }
    
    int Rear() {
        if(curSize && cq) return cq->val;
        return -1;
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == maxSize;
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