
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No *esq, * dir; /* * pai */
} No;

typedef No * p_no;

typedef struct elem{
    p_no no;
    struct elem *seguinte
} elem;

typedef struct Fila {
    elem *inicio, *fim;
} Fila;

typedef Fila *p_fila;

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

void pre_ordem(p_no raiz){
    if (raiz != NULL){
        printf("%d\n", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(p_no raiz){
    if (raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->dado);
    }
}

void in_ordem(p_no raiz){
    if (raiz != NULL){
        in_ordem(raiz->esq);
        printf("%d\n", raiz->dado);
        in_ordem(raiz->dir);
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

p_fila criar_fila(){
    p_fila fila = malloc( sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

bool fila_vazia(p_fila f){
    if (f->inicio == NULL && f->fim == NULL){
        return true;
    }
    return false;
}

void enfileira(p_fila fila, p_no raiz){
    elem *p;
    p = malloc( sizeof(elem));

   // if (p == NULL){
    //    printf('null\n');
   // }
    
    p->no = raiz;
    p->seguinte = NULL;
    if (fila_vazia(fila)){
        fila->inicio = p;
        fila->fim = p;
    }else{
        fila->fim->seguinte = p;
    }
    fila->fim = p;
}

int tamanho(p_fila f){
    elem *p;
    int contador = 0;
    p = f->inicio;
    while (p != NULL)
    {
        contador++;
        p = p->seguinte;
    }
    return contador;
    
}
void mostrar_fila(p_fila f){
    elem *p;
    int tam = tamanho(f);
    int inicio = 0;
    p = f->inicio;
    while (inicio < tam)
    {
        printf("%d\n", p->no->dado);
        p = p->seguinte;
        inicio++;
    }
}

int desenfilerar(p_fila f){
    elem *p;
    if (!fila_vazia(f)){
        
        p = f->inicio;
        f->inicio = p->seguinte;
        if (f->inicio == NULL){
            f->fim = NULL;
        }
        return p->no;
    }else{
        return NULL;
    }
}



void percurso_em_largura(p_no raiz){
    p_fila f;
    f = criar_fila();
    enfileira(f, raiz);
    while(! fila_vazia(f)) {
        raiz = desenfilerar(f);
        if ( raiz != NULL) {
            enfileira(f, raiz -> esq);
            enfileira(f, raiz -> dir);
            printf(" %d ", raiz -> dado);
        }
    }
    printf("\n");
}


p_no criar_arvore(int x);

p_no inserir(p_no raiz, int valor);

void pre_ordem(p_no raiz);

void pos_ordem(p_no raiz);

void in_ordem(p_no raiz);

p_no procurar_no( p_no raiz , int x);

int numero_nos(p_no raiz);

int altura(p_no raiz);

void percurso_em_largura(p_no raiz);

p_fila criar_fila();
bool fila_vazia(p_fila f);

void enfileira(p_fila fila, p_no raiz);
int desenfilerar(p_fila fila);
int tamanho(p_fila f);
void mostrar_fila(p_fila f);



void menu(){
    printf("1 - Criar arvore\n");
    printf("2 - Inserir na arvore\n");
    printf("3 - Altura da arvore\n");
    printf("4 - Total de nos\n");
    printf("5 - Procurar elemento na arvore\n");
    printf("6 - Visualizar arvore pré-ordem\n");
    printf("7 - Visualizar arvore pós-ordem\n");
    printf("8 - Visualizar arvore in-ordem\n");
    printf("9 - Percuso em largura\n");
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
                pre_ordem(arvore);
                printf("--------------------------------------\n");
                break;
            case 7:
                printf("----------------ARVORE----------------\n");
                pos_ordem(arvore);
                printf("--------------------------------------\n");
                break;
            case 8:
                printf("----------------ARVORE----------------\n");
                in_ordem(arvore);
                printf("--------------------------------------\n");
                break;
            case 9:
                printf("----------------ARVORE----------------\n");
                percurso_em_largura(arvore);
                printf("--------------------------------------\n");
                break;
            case 0:

                entrada = 0;
                break;
        }
    }
    
    return 0;

}
