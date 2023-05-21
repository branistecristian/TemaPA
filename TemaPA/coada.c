#include "coada.h"

Queue* createQueue(){
    Queue *q=NULL;
    q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL)
    return NULL;
    q->front=q->rear=NULL;
    return q;
}
void pushQ(Queue *q,Data1 v){
    Node1 *newNode=(Node1*)malloc(sizeof(Node1));
    newNode->Echipe=v;
    newNode->next=NULL;
    if(q->rear==NULL)
    q->rear=newNode;
    else{
        (q->rear)->next=newNode;
        q->rear=newNode;
    }
    if(q->front==NULL)
    q->front=q->rear;
}
int isEmptyQ(Queue *q){
    return (q->front==NULL);
}
void popQ(Queue *q){
    Node1 *aux;
    if(isEmptyQ(q))
    return;
    aux=q->front;
    q->front=(q->front)->next;
    free(aux);
}
Data1 frontQ(Queue *q){
    if(!isEmptyQ(q))
    return q->front->Echipe;
}
Data1 rearQ(Queue *q){
    if(!isEmptyQ(q))
    return q->rear->Echipe;
}
void deleteQueue(Queue *q){
    Node1 *aux;
    while(!isEmptyQ(q))
    {
        aux=q->front;
        q->front=q->front->next;
        free(aux);
    }
    free(q);
}