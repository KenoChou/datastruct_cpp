//
// Created by kenochou on 22-10-11.
//

#ifndef datastruct_cpp_CIREQUEUE_H
#define datastruct_cpp_CIREQUEUE_H
typedef int QElemType;
#define maxSize 20
typedef struct {
    QElemType elem[maxSize];
    int front,rear;

}CireQueue;
void InitQueue(CireQueue &Q){
    Q.front=Q.rear=0;
};
int EnQueue(CireQueue &Q, QElemType x){
    if((Q.rear+1) % maxSize==Q.front) return 0;
    Q.elem[Q.rear]=x;
    Q.rear=(Q.rear+1) % maxSize;
    return 1;
};
int QueueEmpty(CireQueue &Q){
    return Q.front==Q.rear;
};
int QueueFull(CireQueue & Q){
    return (Q.rear+1) % maxSize==Q.front;
};
int QueueSize(CireQueue& Q){
    return (Q.rear-Q.front+maxSize) % maxSize;
};
#endif //datastruct_cpp_CIREQUEUE_H
