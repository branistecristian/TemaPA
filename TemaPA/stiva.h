#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Data.h"

void pushS(Node**top,Data v);
void popS(Node**top);
Data topS(Node *top);
int isEmptyS(Node *top);
void deleteStack(Node**top);
