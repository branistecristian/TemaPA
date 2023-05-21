#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Data.h"
#include "stiva.h"
#include "BST.h"

int compareAVL(Data Echipa1,Data Echipa2);
int nodeHeight(Node3 *root);
int max(int a,int b);
Node3 *RightRotation(Node3 *z);
Node3 *LeftRotation(Node3 *z);
Node3 *LRRotation(Node3 *z);
Node3 *RLRotation(Node3 *z);
Node3 *insertAVL(Node3 *node,Data Echipa);
void AfisareNivel2AVL(Node3 *node,Node **List,FILE *g);
void extractValuesAndInsertAVL(Node2 *node, Node3 **treeAVL);
void AfisareAVL(Node3 *node,FILE *g);
