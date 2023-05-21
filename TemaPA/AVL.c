#include "AVL.h"
#include <string.h>

int compareAVL(Data Echipa1,Data Echipa2)
{
    if(Echipa1.Score<Echipa2.Score)
    return 1;
    else if(Echipa1.Score==Echipa2.Score&&strcmp(Echipa1.Team,Echipa2.Team)<0)
    return 1;
    else return 0;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int nodeHeight(Node3 *root)
{
    if(root == NULL)
    return -1;
    else return 1+max(nodeHeight(root->left),nodeHeight(root->right));
}

Node3 *RightRotation(Node3 *z)
{
    Node3 *y=z->left;
    Node3 *T3=y->right;

    y->right=z;
    z->left=T3;

    z->height=max(nodeHeight(z->left),nodeHeight(z->right))+1;
    y->height=max(nodeHeight(y->left),nodeHeight(y->right))+1;

    return y;
}

Node3 *LeftRotation(Node3 *z)
{
    Node3 *y=z->right;
    Node3 *T2=y->left;
    
    y->left=z;
    z->right=T2;

    z->height=max(nodeHeight(z->left),nodeHeight(z->right))+1;
    y->height=max(nodeHeight(y->left),nodeHeight(y->right))+1;

    return y;
}

Node3 *LRRotation(Node3 *z)
{
    z->left=LeftRotation(z->left);
    return RightRotation(z);
}

Node3 *RLRotation(Node3 *z)
{
    z->right=RightRotation(z->right);
    return LeftRotation(z);
}

Node3 *insertAVL(Node3 *node,Data Echipa)
{
    if(node == NULL)
    {
        node=malloc(sizeof(Node3));
        node->Echipa=Echipa;
        node->height=0;
        node->left=node->right=NULL;
        return node;
    }
    else{
        if(compareAVL(Echipa,node->Echipa))
        node->left=insertAVL(node->left,Echipa);
        else if(!compareAVL(Echipa,node->Echipa))
        node->right=insertAVL(node->right,Echipa);
        else return node;

        node->height=max(nodeHeight(node->left),nodeHeight(node->right))+1;

        int k=nodeHeight(node->left)-nodeHeight(node->right);

        if(k>1 && compareAVL(Echipa,node->left->Echipa))
        return RightRotation(node);

        if(k<-1 && !compareAVL(Echipa,node->right->Echipa))
        return LeftRotation(node);

        if(k>1 && !compareAVL(Echipa,node->left->Echipa))
        return RLRotation(node);

        if(k<-1 && compareAVL(Echipa,node->right->Echipa))
        return LRRotation(node);

        return node;        

    }
}

void AfisareNivel2AVL(Node3 *node,Node **List,FILE *g)
{
    if(node==NULL||node->height<1)
    return;
    else
    {
        Data Echipa=node->Echipa;
        pushS(List,Echipa);
        // fprintf(g,"%s\n",Echipa.Team);
    }
    AfisareNivel2AVL(node->left,List,g);
    AfisareNivel2AVL(node->right,List,g);
}

void extractValuesAndInsertAVL(Node2 *node, Node3 **treeAVL) {
    if(node == NULL) 
    return;

    Data Echipa = node->Echipa;
    *treeAVL = insertAVL(*treeAVL, Echipa);

    extractValuesAndInsertAVL(node->left, treeAVL);
    extractValuesAndInsertAVL(node->right, treeAVL);
}

void AfisareAVL(Node3 *node,FILE *g)
{
    if(node)
    {
        Data Echipa;
        Echipa=node->Echipa;
        fprintf(g,"%s %.2f %d\n",Echipa.Team,Echipa.Score,node->height);
        AfisareAVL(node->left,g);
        AfisareAVL(node->right,g);
    }
}