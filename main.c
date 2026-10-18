#include<stdio.h>
#include<stdlib.h>

struct lista{
    int info;
    struct lista * next;
};
typedef struct lista Lista;

Lista * inicializaLista(){
    return NULL;
}

Lista * inserirComecoLista(Lista * pL, int valor){
    Lista * novo;
    novo = (Lista *) malloc(sizeof(Lista));
    if(novo != NULL){
        novo->info = valor;
        novo->next = pL;
    }
    return novo;
}

void imprimir(Lista * pL){
    while(pL != NULL){
        printf("[%d]->", pL->info);
        pL = pL->next;
    }
    printf("\n");
}

//Aqui implementei 2 funções para resover os exercícios

Lista * pesquisar(Lista * pL, int valor) {
    while(pL != NULL){
        if(pL->info == valor) {
            return pL;
        }
        pL = pL->next;
    }
return NULL;
}

Lista * dividir(Lista * pL, int valor) {

    Lista * pesquisa = pesquisar(pL,valor);

    if (pesquisa == NULL) {
        return NULL;
    }
    Lista * novaL = pesquisa->next;
    pesquisa->next = NULL;

    return novaL;
}

int main(){

    Lista * L;
    L = inicializaLista();

    L = inserirComecoLista(L,10);
    L = inserirComecoLista(L, 5);
    L = inserirComecoLista(L, 1);

    printf("Lista Original: ");
    imprimir(L);
//A partir daqui ficam os chamamentos das funções e alguns outros códigos que implementei para resolver
//os exercícios.
    Lista * pesquisa = pesquisar(L,2);

    if(pesquisa != NULL) {
        printf("\nRetorno da pesquisa: %d", pesquisa->info);
    }

    Lista * NovaLista = dividir(L,5);

    printf("Nova Lista: ");
    imprimir(NovaLista);
    printf("Lista antiga: ");
    imprimir(L);

    return 0;
}