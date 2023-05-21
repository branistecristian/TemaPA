#include "BST.h"
#include <string.h>

int compare(Data Echipa1,Data Echipa2)
{
    if(Echipa1.Score<Echipa2.Score)
    return 1;
    else if(Echipa1.Score==Echipa2.Score&&strcmp(Echipa1.Team,Echipa2.Team)<0)
    return 1;
    else return 0;
}

Node2 *newNode(Data Echipa)
{
    Node2* node=malloc(sizeof(Node2));
    node->Echipa=Echipa;
    node->left=node->right=NULL;
    return node;
}

Node2 *insert(Node2* node,Data Echipa)
{
    if(node==NULL)
    return newNode(Echipa);
    else{
        if(compare(Echipa,node->Echipa))
        node->left=insert(node->left,Echipa);
        else node->right=insert(node->right,Echipa);
        return node;
    }
}

void inordine(Node2* node,Node** Lista,FILE *g)
{
    if(node)
    {
        inordine(node->right,Lista,g);
        Data Echipa=node->Echipa;
        pushS(Lista,Echipa);
        fprintf(g,"%s",Echipa.Team);
        for(int i=0;i<34-strlen(Echipa.Team);i++)
        fprintf(g," ");
        fprintf(g,"-  %.2f\n",Echipa.Score);
        inordine(node->left,Lista,g);
    }
}