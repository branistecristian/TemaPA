#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Data.h"

typedef struct{
    Data firstTeam;
    Data secondTeam;
}Data1;

typedef struct Elem1{
    Data1 Echipe;
    struct Elem1* next;
}Node1;

typedef struct Q{
    Node1 *front,*rear;
}Queue;

Queue* createQueue();
void pushQ(Queue *q,Data1 v);
int isEmptyQ(Queue *q);
void popQ(Queue *q);
Data1 frontQ(Queue *q);
Data1 rearQ(Queue *q);
void deleteQueue(Queue *q);