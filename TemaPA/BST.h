#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Data.h"
#include "stiva.h"

int compare(Data Echipa1,Data Echipa2);
Node2 *newNode(Data Echipa);
Node2 *insert(Node2* node,Data Echipa);
void inordine(Node2* node,Node** Lista,FILE* g);