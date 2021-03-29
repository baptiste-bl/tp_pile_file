#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete = -1;
    ptrF->Queue = -1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{

    if(fileVide(ptrF)!=1){
        *ptrE = (ptrF->Elts[0]);
        for(int i = 0; i<ptrF->Queue; i++){
            //ptrF->Elts[i] = ptrF->Elts[i+1];
            affecterElt(&(ptrF->Elts[i]),&(ptrF->Elts[i+1]));
        }
        ptrF->Queue--;
        return 1;
    }
    else{
        return 0;
    }
}
int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if(filePleine(ptrF)){
        return 0;
    }
    else{
        ptrF->Queue++;
        affecterElt(&(ptrF->Elts[ptrF->Queue]),ptrE);
        //ptrF->Elts[ptrF->Queue] = *ptrE;
        if(ptrF->Tete==-1){
            ptrF->Tete=0;
        }
        return 1;
    }
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0 return 0;

{
    if(ptrF->Tete == ptrF->Queue+1){
        return 1;
    }
    else return 0 ; 
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    
    if((ptrF->Queue+1) == MAX){
        return 1;
    }
    else return 0;
}
T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    T_Elt elem;
    if(fileVide(ptrF)!=1){
        elem = ptrF->Elts[ptrF->Tete];
        return elem;
    }
    else return 0;
    
}

void afficherFile(T_File *ptrF)
{
    T_Elt e;
    for(int i =0; i<=ptrF->Queue; i++){
        retirer(ptrF,&e);
        printf("%d\n",e);
        ajouter(ptrF,&e);
    }

}

void testFile(T_File *ptrF){
    initFile(ptrF);
    T_Elt a = 5;
    T_Elt b = 6;
    T_Elt c = 7;
    T_Elt d = 8;
    T_Elt e;
    printf("ajout de 5, 6, 7 \n");
    ajouter(ptrF,&a);
    ajouter(ptrF,&b);
    ajouter(ptrF,&c);
    printf("affichage de la file\n");
    afficherFile(ptrF);

    printf("\npremier = %d \n" ,premier(ptrF));
    printf("fonction retirer\n");
    retirer(ptrF,&e);
    afficherFile(ptrF);
    printf("\najout de l'element retirer\n");
    ajouter(ptrF,&e);
    afficherFile(ptrF);
    printf("\najout de plein de 5");

    for(int i =0; i<5; i++){
        ajouter(ptrF,&a);
        

    }
    afficherFile(ptrF);
    printf("\nplein ou pas : %d",filePleine(ptrF));
    printf("\non retire plusieurs fois\n");
    for(int i =0; i<20; i++){
        retirer(ptrF,&a);
    }
    afficherFile(ptrF);
    printf("\nfile vide : %d",fileVide(ptrF));
}




