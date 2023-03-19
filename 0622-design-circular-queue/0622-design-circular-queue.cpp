class MyCircularQueue {
    int* arr;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) {
        size=k;
        arr= new int[size];
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if((front==0 && rear==size-1)|| ((rear==(front-1) && front!=0))){
            //cout<<"queue is full "<<endl;
            return false;
        }
        
        else if(front==-1)//first element to be pushed
        {
            front=rear=0;
            arr[rear]=value;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front==-1){cout<<"queue is empty"<<endl;return false;}
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){//single element is present
            front=rear=-1;
        }
        else if(front==size-1){
             front=0;
        }
        else{front++;}
        return true;
    }
    
    int Front() {
        if(front==-1){cout<<"Queue is empty "<<endl;return -1;}
        else{return arr[front];}
    }
    
    int Rear() {
        if(front==-1){cout<<"Queue is empty "<<endl;return -1;}
        else{return arr[rear];}
    }
    
    bool isEmpty() {
        if(front==-1){return true;}
        else{return false;}
    }
    
    bool isFull() {
        if((front==0 && rear==size-1)|| (rear==(front-1)%(size-1))){
            //cout<<"queue is full "<<endl;
            return true;
        }
        else{return false;}
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