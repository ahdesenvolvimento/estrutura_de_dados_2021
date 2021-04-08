
class ArvoreBinaria():
    def __init__(self, dado=None, direita=None, esquerda=None, pai=None):
        self.dado = dado
        self.dir = direita
        self.esq = esquerda
        self.pai = pai
    
    def __repr__(self):
        return "%s <- %s -> %s" %(self.esq and self.esq.dado, 
                                  self.dado,
                                  self.dir and self.dir.dado)
            
def insere(raiz, nodo):
    if raiz is None:
        raiz = nodo
    elif raiz.dado > nodo.dado:
        if raiz.esq is None:
            raiz.esq = nodo
            raiz.esq.pai = raiz
        else:
            insere(raiz.esq, nodo)
    elif raiz.dado < nodo.dado:
        if raiz.dir is None:
            raiz.dir = nodo
            raiz.dir.pai = raiz
        else:
            insere(raiz.dir, nodo)
        
def procura_no(raiz, valor):
    if raiz is None or raiz.dado == valor:
        return raiz;
    direita = procura_no(raiz.dir, valor)
    if direita != None:
        return direita
    esquerda = procura_no(raiz.esq, valor)
    return esquerda

def numero_nos(raiz):
    if raiz is None:
        return 0
    return numero_nos(raiz.dir) + numero_nos(raiz.esq) + 1

def imprimir_arvore(raiz):
    if raiz != None:
        print(raiz)
        imprimir_arvore(raiz.dir)
        #imprimir_arvore(raiz.esq)
        
def remover_no(raiz, valor):
    direita = procura_no(raiz, valor)
    if direita != None:
      #  print(direita.pai, direita)
        if direita.pai.dado > valor:
            direita.pai.esq = None
           # print("é maior hehehehe direita", direita.pai.dado, valor)
        else:
            direita.pai.dir = None
            #print("é menor heheh esquerda")

def altura(raiz):
    if raiz == None or (raiz.dir == None and raiz.esq == None):
        return 0
    else:
        direita = altura(raiz.dir)
        print("direita", direita)
        esquerda = altura(raiz.esq)
        if direita != None and esquerda != None:
            if direita > esquerda:
                return 1 + altura(raiz.dir)
            else:
                return 1 + altura(raiz.esq)
def main():
    arvore = ArvoreBinaria(3)
 
    for dado in [20, 60, 50, 70, 10, 30]:
        nodo = ArvoreBinaria(dado)
        
        insere(arvore, nodo)
       
    z = altura(arvore)
    print(z)
    x = procura_no(arvore, 50)
    y = remover_no(arvore, 50)
    imprimir_arvore(arvore)
   # print("aqui num123213rp", numero_nos(arvore))
    #print("aqui achei o valor 50", x)
    #print(arvore)
   # arvore.inserir_valor(arvore, 5, 1)
    #arvore.inserir_valor(arvore, 1, 1)
  #  arvore.esq = ArvoreBinaria(30)
  #  arvore.esq.esq = ArvoreBinaria(30)
   # arvore.dir = ArvoreBinaria(30)
   # arvore.dir.esq = ArvoreBinaria(30)
    

main()