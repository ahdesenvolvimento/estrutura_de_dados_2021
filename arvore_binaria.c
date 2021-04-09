
#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int dado;
    struct No *esq, * dir; /* * pai */
} No;

typedef No * p_no;

p_no criar_arvore(int x) {
    p_no r = malloc( sizeof(No));

    r-> dado = x;
    r-> esq = NULL;
    r-> dir = NULL;

    return r;
}

p_no inserir(p_no raiz, int valor){

    if (raiz == NULL){
        raiz = (p_no)malloc(sizeof(No));
        raiz->dado = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    else if (valor > raiz->dado){

        raiz->dir =  inserir(raiz->dir, valor);

    }else if (valor < raiz->dado){

        raiz->esq =  inserir(raiz->esq, valor);
    }

    return raiz;
}

void visualizar_arv(p_no raiz){
    if (raiz != NULL){
        printf("%d\n", raiz->dado);
        visualizar_arv(raiz->dir);
        visualizar_arv(raiz->esq);
    }
}

int numero_nos(p_no raiz){

    if (raiz == NULL){
        return 0;
    }
    return numero_nos(raiz->dir) + numero_nos(raiz->esq) + 1;
}

p_no procurar_no(p_no raiz , int x) {
    p_no esq;
    if ( raiz == NULL || raiz -> dado == x)
    return raiz;
    esq = procurar_no(raiz ->esq, x);
    if ( esq != NULL)
        return esq;
    return procurar_no(raiz ->dir, x);
}

int altura(p_no raiz){
    int h_esq, h_dir;
    if (raiz == NULL){
        return 0;
    }
    h_esq = altura(raiz -> esq);
    h_dir = altura(raiz -> dir);
    return 1 + ( h_esq > h_dir ? h_esq : h_dir);
}

p_no criar_arvore(int x);

p_no inserir(p_no raiz, int valor);

void visualizar_arv(p_no raiz);

p_no procurar_no( p_no raiz , int x);

int numero_nos(p_no raiz);

int altura(p_no raiz);

void menu(){
    printf("1 - Criar arvore\n");
    printf("2 - Inserir na arvore\n");
    printf("3 - Altura da arvore\n");
    printf("4 - Total de nos\n");
    printf("5 - Procurar elemento na arvore\n");
    printf("6 - Visualizar arvore\n");
    printf("0 - Sair\n");
}

void menu();

int main(){
    int entrada = 1;
    while (entrada != 0){
        int valor, numero, alt, *proc;
        menu();
        printf("Selecione uma opcao abaixo: \n");
        scanf("%d", &valor);
        switch (valor){
            case 1:
                printf("Digite o valor que deseja para iniciar a arvore: ");
                scanf("%d", &valor);
                p_no arvore = criar_arvore(valor);
                break;
            case 2:
                printf("Digite o valor que deseja inserir na arvore: ");
                scanf("%d", &valor);
                inserir(arvore, valor);
                break;
            case 3:

                alt = altura(arvore);
                printf("Altura da arvore eh: %d\n", alt);
                break;
            case 4:
                numero = numero_nos(arvore);
                printf("A arvore tem %d nos\n", numero);
                break;
            case 5:
                printf("Digite o valor que deseja procurar: ");
                scanf("%d", &valor);
                proc = procurar_no(arvore, valor);
                if (proc == NULL){
                    printf("Valor %d nao esta na arvore\n", valor);
                }else{
                    printf("Valor %d foi encontrado na arvore\n", valor);
                }
                break;
            case 6:
                printf("----------------ARVORE----------------\n");
                visualizar_arv(arvore);
                printf("--------------------------------------\n");
                break;
            case 0:

                entrada = 0;
                break;
        }
    }
   // p_no arvore = criar_arvore(5);
   // p_no a = inserir(arvore, 7, 1);
   // p_no b = inserir(arvore, 2, 1);
   // p_no c = inserir(arvore, 6, 1);
   // visualizar_arv(arvore);
   // int x = numero_nos(arvore);
   // printf("%d here\n", x);


    return 0;
}
