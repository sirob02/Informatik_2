#include "../lib/buecher_func.h"

/**TODO
 *  check if Author available otherwise add new
 * @return poistion of Author                        */
int getAuthorPos(Autor autoren[],int *num_autor,char *tmpAutor,const int MAXAUTOR){
    
    //check if Author is available
    for(int pos = 0; pos < *num_autor; pos++){
        if (strcmp(autoren[pos].name,tmpAutor) == 0){
            return pos;
        }
    }
    //not available
    if (*num_autor < MAXAUTOR){
        autoren[*num_autor].name = tmpAutor;
        *num_autor += 1;
        return (*num_autor)-1;
    }else{
        printf("ERROR: Zu viele Autoren\n");
        return -1;
    }
}

/**TODO
 *  check if Verlag available otherwise add new
 * @return poistion of Verlag                        */
int getVerlagPos(Verlag verlage[],int *num_verlag,char *tmpVerlag,const int MAXVERLAG){
        
    //check if Verlag is available
    for(int pos = 0; pos < *num_verlag; pos++){
        if (strcmp(verlage[pos].name,tmpVerlag) == 0){
            return pos;
        }
    }
    //not available
    if (*num_verlag < MAXVERLAG){
        verlage[*num_verlag].name = tmpVerlag;
        *num_verlag += 1;
        return (*num_verlag)-1;
    }else{
        printf("ERROR: Zu viele Verlage\n");
        return -1;
    }
}

/**TODO
 * create Permutationsvektor of Verlag  */
void createVerlagPerm(Verlag *vPerm[],Verlag verlage[],int MAXVERLAG){
    for(int i = 0; i<MAXVERLAG; i++){
        vPerm[i] = &(verlage[i]);
    }
}

/**TODO
 *  sort Verlage and print top N  */
void printTopVerlage(Verlag* vPerm[],int num_verlag,int N){
    qsort(vPerm,num_verlag,sizeof(vPerm[0]),cmpVerlage);
    
    for(int i = 0; (i < N) && (i < num_verlag); i++){
        printf("%2d: (%3d) %s\n",i+1,vPerm[i]->anz_buecher, vPerm[i]->name);
    }
}


/** TODO
 *  compare Books of Verlage    */
int cmpVerlage(const void *a,const void *b){
    const Verlag aV = **(const Verlag**)a;
    const Verlag bV = **(const Verlag**)b;

    return bV.anz_buecher - aV.anz_buecher;
}

/**TODO
 *  create Permutationsvektor of Author */
void createAuthorPerm(Autor *aPerm[],Autor autoren[],int MAXAUTOR){
    for(int i = 0; i< MAXAUTOR; i++){
        aPerm[i] = &(autoren[i]);
    }
}

/**TODO
 *  print Top N Autoren */
void printTopAutoren(Autor* aPerm[],int num_autor,int N){
    qsort(aPerm,num_autor,sizeof(aPerm[0]),cmpAutoren);

    for(int i = 0; (i < N) && (i < num_autor) ; i++){
        printf("%2d: (%3d) %s\n",i+1,aPerm[i]->anz_buecher, aPerm[i]->name);
    }
}

/**TODO
 * compare Books of Authors */
int cmpAutoren(const void *a,const void *b){
    const Autor aA = **(const Autor**)a;
    const Autor bA = **(const Autor**)b;

    return bA.anz_buecher - aA.anz_buecher;
}