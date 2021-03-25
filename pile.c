#include "pile.h"



void initPile( T_Pile * P)
{
    P->nbElts = 0;
}

int pilepleine(const  T_Pile *P)
{
    if((P->nbElts) == MAX)
    {
        return 1;
    }
return 0;
}

int pilevide(const  T_Pile *P)
{
    if((P->nbElts) == 0)
    {
        return 1;
    }   
return 0;
}



int empiler( T_Pile *P, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    if(pilepleine(P) == 0)
    {
        affecterElt(&(P->Elts[P->nbElts]),&e);
        (P->nbElts)++;
        return 1;
    }
    printf("erreur pile pleine");
return 0;
}



int depiler( T_Pile *P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if(pilevide(P) == 0)
    {
        *pelt = P->Elts[P->nbElts-1];
        (P->nbElts)--;
        return 1;
    }
    printf("erreur pile vide");
return 0;
}



T_Elt sommet(const  T_Pile *P)
{
    if(pilevide(P) == 0)
    {
        return P->Elts[P->nbElts-1];
    }
return 0;
}



int hauteur(const  T_Pile *P)
{
    if(pilevide(P) == 0)
    {
        return P->nbElts-1;
    }
return 0;
}


void afficherPile(  T_Pile *P)
{
    T_Elt e ;
    T_Pile P2;
    int i;
    int ret = P->nbElts;
    initPile(&P2);
    for(i = 0; i < ret;i++)
    {
        depiler(P,&e);
        printf("%d\n",e);
        empiler(&P2,e);
    }
    for(i = 0; i < ret;i++)
    {
        depiler(&P2,&e);
        empiler(P,e);
    }   
}
void testPile(T_Pile *P)
{
    T_Elt e;
    T_Elt test = 10;
    initPile(P);
    printf("\najout de 10 dans la pile\n");
    empiler(P,test);
    printf("\najout de 20 dans la pile\n");
    test= 20;
    empiler(P,test);
    printf("\naffichage de la pile\n");
    afficherPile(P);
    printf("\ndépiler\n");
    depiler(P,&test);
    printf("\naffichage de la pile\n");
    afficherPile(P);
    printf("\najout de 30 dans la pile\n") ;  
    empiler(P,30);
    printf("\naffichage du sommet\n");
    printf("%d",sommet(P));
    printf("affichage de la hauteur\n");
    printf("%d\n",hauteur(P));
    depiler(P,&test);
    depiler(P,&test);
    printf("depiler une pile vide:\n");
    depiler(P,&test);
}








