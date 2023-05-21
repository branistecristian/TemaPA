#include "stiva.h"
#include "coada.h"
#include "BST.h"
#include "AVL.h"
#include <string.h>

int main(int argc,char *arvg[])
{
    char *buff=malloc(100);
    Node *Lista=NULL;
    Node *ListaOG=NULL;
    Node *ListaTop8=NULL;
    Node *ListaTop8SortataCrescator=NULL;
    Node *ListaTop8SortataDescrescator=NULL;
    Node2 *tree=NULL;
    Node3 *treeAVL=NULL;
    int NumarEchipe,NumarEchipe1;

    FILE *f1=fopen(arvg[1],"rt");
    if(f1== NULL){
        printf("Eroare!");
        exit(1);
    }
    FILE *f2=fopen(arvg[2],"rt");
    if(f2== NULL){
        printf("Eroare!");
        exit(1);
    }
    FILE *g=fopen(arvg[3],"wt");
    if(g==NULL)
    {
        printf("Eroare!");
        exit(1);
    }

    int *VectorCerinte=malloc(5*sizeof(int));
    for(int i=0;i<5;i++)
    fscanf(f1,"%d",&VectorCerinte[i]);
    
    if(VectorCerinte[0]) // Prima cerinta
    {
        fscanf(f2,"%d",&NumarEchipe);
        for(int i=0;i<NumarEchipe;i++)
        {
            // Citirea datelor unei echipe
            // --------------------------------------------------------------------------------------------------------------

            Data Echipa;
            fscanf(f2,"%d",&(Echipa.numberPlayers));
            fgetc(f2);
            fgets(buff,100,f2);
            Echipa.Team=strdup(buff);
            Echipa.Team[strlen(Echipa.Team)-1]='\0';
            Echipa.Team[strlen(Echipa.Team)-1]='\0';
            Player *Jucatori=malloc(Echipa.numberPlayers*sizeof(Player));
            Echipa.Score=0;
            for(int j=0;j<Echipa.numberPlayers;j++)
            {
                fscanf(f2,"%s",buff);
                Jucatori[j].firstName=strdup(buff);
                fscanf(f2,"%s",buff);
                Jucatori[j].secondName=strdup(buff);
                fscanf(f2,"%d",&Jucatori[j].points);
                Echipa.Score+=Jucatori[j].points;
                fgetc(f2);
            }
            fgetc(f2);
            Echipa.Score/=Echipa.numberPlayers;
            Echipa.Jucatori=Jucatori;

            // --------------------------------------------------------------------------------------------------------------

            // printf("%d\n",Echipa.numberPlayers);
            // printf("%s\n",Echipa.Team);
            // for(int j=0;j<Echipa.numberPlayers;j++)
            // {
            //     printf("%s %s %d\n",Echipa.Jucatori[j].firstName,Echipa.Jucatori[j].secondName,Echipa.Jucatori[j].points);
            // }

            // --------------------------------------------------------------------------------------------------------------

            // Adaugarea la inceput a echipei in lista 

            pushS(&Lista,Echipa);
            pushS(&ListaOG,Echipa);
        }
        if(!VectorCerinte[1]){ // Afisarea Listei
            
            Node *aux=Lista;
            while(!isEmptyS(aux))
            {
            Data Echipa=topS(aux);
            fprintf(g,"%s\n",Echipa.Team);
            popS(&aux);
            }
            deleteStack(&aux);
        }
    }
    if(VectorCerinte[1]) // A doua cerinta
    {

        Node *aux=Lista;

        // Algoritm :

        // Aflam minimul dupa fiecare parcurgere , eliminand astfel echipa cu cel mai mic punctaj pana la completarea listei
        // Complexitate timp max O(n^2)

         // --------------------------------------------------------------------------------------------------------------

        // Aflarea numarului de echipe 
        
        NumarEchipe1=NumarEchipe;
        int contor1=0;
        while(NumarEchipe1)
        {
            contor1++;
            NumarEchipe1>>=1;
        }
        NumarEchipe1=1<<(contor1-1);
        
        // Eliminam echipele in functie de minimul gasit dupa fiecare parcurgere de NumarEchipe-NumarEchipe1 ori

        float min;
        int contor=NumarEchipe-NumarEchipe1;
        while(contor--){

            min=1e9;

          // Gasirea punctajului minim

            aux=Lista;
            while(aux){
            
            Data Echipa=aux->Echipa;
            if(min>Echipa.Score)
            min=Echipa.Score;
            aux=aux->next;
            }

          // Eliminarea echipei cu punctaj minim

          if((Lista->Echipa).Score==min)
        {

            Node *aux1=Lista;
            Lista=Lista->next;
            free(aux1);
        }
        else{
            aux=Lista;
            while(aux->next){

            Data Echipa=aux->next->Echipa;

            if(Echipa.Score==min){
                Node *aux1=aux->next;
                aux->next=aux->next->next;
                free(aux1);
                break;
                }

            else aux=aux->next;
            }
          }
        }

         // --------------------------------------------------------------------------------------------------------------

        aux=Lista;
        while(aux)
             {
                Data Echipa=aux->Echipa;
                fprintf(g,"%s\n",Echipa.Team,Echipa.Score);
                aux=aux->next;
             }
        free(aux);

    }
    if(VectorCerinte[2]) // A treia cerinta 
    {
        int contor=NumarEchipe1>>1,runda=0;
        Node *aux=Lista;
        while(contor)
        {
            runda++;
            fprintf(g,"\n--- ROUND NO:%d\n",runda);
        // --------------------------------------------------------------------------------------------------------------
            // Crearea cozii de meciuri

            Queue *Q=createQueue();
            
            while(aux)
            {
                
                if(aux->Echipa.Team[strlen(aux->Echipa.Team)-1]==32)
                   aux->Echipa.Team[strlen(aux->Echipa.Team)-1]='\0';
                if(aux->next->Echipa.Team[strlen(aux->next->Echipa.Team)-1]==32)
                   aux->next->Echipa.Team[strlen(aux->next->Echipa.Team)-1]='\0';

                
                Data Echipa1=aux->Echipa;
                Data Echipa2=aux->next->Echipa;
                Data1 Meci;
                Meci.firstTeam=Echipa1;
                Meci.secondTeam=Echipa2;

                pushQ(Q,Meci); // Adaugarea meciului in coada

                aux=aux->next->next;
            }

            // Afisarea cozii formatata , cat si crearea stivelor

            Queue *Q1=Q;
            Node *ListaCastigatori=NULL;
            Node *ListaInvinsi=NULL;
            while(!isEmptyQ(Q1))
            {
                Data1 Meci;
                Data Echipa1,Echipa2,Winner,Loser;
                Meci=frontQ(Q1);
                Echipa1=Meci.firstTeam;
                Echipa2=Meci.secondTeam;

                // Afisarea spatiilor pentru formatarea corecta

                fprintf(g,"%s",Echipa1.Team);
                for(int i=0;i<33-strlen(Echipa1.Team);i++)
                fprintf(g," ");
                fprintf(g,"-");
                for(int i=0;i<33-strlen(Echipa2.Team);i++)
                fprintf(g," ");
                fprintf(g,"%s\n",Echipa2.Team);

                //Aflarea Echipei Castigatoare
                
                if(Echipa1.Score<=Echipa2.Score)
                Winner=Echipa2,Loser=Echipa1;
                else Winner=Echipa1,Loser=Echipa2;
                Winner.Score+=1;

                //Adaugarea echipelor in stive

                pushS(&ListaCastigatori,Winner);
                pushS(&ListaInvinsi,Loser);

                // Eliminarea din coada

                popQ(Q1);
            }
            
            // Afisarea stivei de castigatori , cat si punctajul echipei

            fprintf(g,"\nWINNERS OF ROUND NO:%d\n",runda);

            Node *winners=ListaCastigatori;
            while(!isEmptyS(winners))
            {
                Data Echipa=topS(winners);
                fprintf(g,"%s",Echipa.Team);
                for(int i=0;i<34-strlen(Echipa.Team);i++)
                fprintf(g," ");
                fprintf(g,"-  %.2f\n",Echipa.Score);
                winners=winners->next;
            }
            deleteQueue(Q);

            // Salvarea listei cu cei 8 jucatori pentru urmatoarele cerinte

            if(contor==8)
            {
                winners=ListaCastigatori;
                while(!isEmptyS(winners))
                {
                Data Echipa=topS(winners);
                pushS(&ListaTop8,Echipa);
                winners=winners->next;
                }
            }

            // Trecerea la urmatoarea runda

            aux=ListaCastigatori;
            contor >>= 1;

            // --------------------------------------------------------------------------------------------------------------
        }
    }
    if(VectorCerinte[3]) // A patra cerinta
    {
        Node *aux=ListaTop8;
        
         // Algoritm :

         // Construim arborele de tip BST , apoi pentru a afla ordinea echipelor in functie de cerinta parcurgem in-ordine arborele ( de la dreapta la stanga )

         // Complexitate O(n log n)

        // --------------------------------------------------------------------------------------------------------------

         // Crearea arborelui

         while(aux)
         {
            Data Echipa=aux->Echipa;
            tree=insert(tree,Echipa);
            aux=aux->next;
         }

         // Afisarea arborelui dupa parcurgerea in-ordine 

         fprintf(g,"\nTOP 8 TEAMS:\n");

         inordine(tree,&ListaTop8SortataCrescator,g);

        // --------------------------------------------------------------------------------------------------------------
    }
    if(VectorCerinte[4]) // A cincea cerinta
    {

       // --------------------------------------------------------------------------------------------------------------

        //  while(aux)
        //  {
        //     Data Echipa=aux->Echipa;
        //     pushS(&ListaTop8SortataDescrescator,Echipa);
        //     aux=aux->next;
        //  }

         extractValuesAndInsertAVL(tree,&treeAVL);

        //  aux=ListaTop8SortataDescrescator;
         
        //  // Crearea arborelui AVL

        //  while(aux)
        //  {
        //     Data Echipa=aux->Echipa;
        //     treeAVL=insertAVL(treeAVL,Echipa);
        //     aux=aux->next;
        //  }

        //  // Afisarea echipelor de pe nivelul 2 al arborelui AVL

         fprintf(g,"\nTHE LEVEL 2 TEAMS ARE: \n");

         Node *List=NULL;

         AfisareNivel2AVL(treeAVL,&List,g);

         Node *aux=List;

         while(aux->next)
         {
            Data Echipa1=aux->Echipa;
            Node *aux1=aux->next;
            
            while(aux1)
            {
                Data Echipa2=aux1->Echipa;
                if(compareAVL(Echipa1,Echipa2))
                {
                    Data Echipa3=aux1->Echipa;
                    aux1->Echipa=aux->Echipa;
                    aux->Echipa=Echipa3;
                }
                aux1=aux1->next;
            }
            
            aux=aux->next;
         }
         
         aux=List;
         while(aux)
         {
            Data Echipa=aux->Echipa;
            fprintf(g,"%s\n",Echipa.Team);
            aux=aux->next;
         }
         //AfisareAVL(treeAVL,g);

       // --------------------------------------------------------------------------------------------------------------

    }
    
    fclose(g);

    return 0;
}