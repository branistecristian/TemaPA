#include "stiva.h"

void pushS(Node**top,Data v){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->Echipa=v;
    newNode->next=*top;
    *top=newNode;
}
void popS(Node**top){
    if(isEmptyS(*top))
    return;
    Node *temp=(*top);
    *top=(*top)->next;
    free(temp);
}
Data topS(Node *top){
    if(!isEmptyS(top))
    return top->Echipa;
}
int isEmptyS(Node *top){
    return top==NULL;
}
void deleteStack(Node**top){
    Node *temp;
    while((*top)!=NULL){
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}