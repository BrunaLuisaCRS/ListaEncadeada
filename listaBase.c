#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//__________---__________(criando o tipo nó)____________---_____________//

typedef struct nó{
    
    int valor;
    struct nó *prox;
    
}Nó;

//______________________procedimento para inserir no início_____________________//

void insertInicio(Nó **lista, int v){
    
    Nó *novo = malloc(sizeof(Nó));  //cria um novo nó com o tamanho de nó
    
    
    if (novo){
        
        novo->valor = v;  // o valor do nó novo recebe o valor recebido pela função
        novo->prox = *lista; // o novo nó aponta para o primeiro nó da lista
        *lista = novo;
        
    }else printf("Erro de alocação de memória.");
    
    
}

//______________________procedimento pra inserir no meio________________________//

void inserir_meio (Nó **lista, int num, int anterior){
    
    Nó *aux, *novo = malloc(sizeof(Nó));
    
    if(novo){
        
       novo->valor = num; 
        
       // é o primeiro elemento?
       if(*lista == NULL){
           novo->prox = NULL;
           *lista = novo;
       }else{
           
           aux = *lista;
           
           while(aux->valor != anterior && aux->prox){ /* enquanto não achar o valor e
                                                         existir um próximo valor */
                                                         
               aux = aux->prox; // auxiliar vai indo pro proximo
           }
           novo->prox = aux->prox; // o novo próximo aponta para o próximo do aux
           aux->prox = novo;      // o próximo do auxiliar recebe o novo
       }
    }else printf("Erro de alocação de memória");
    
}


//____________________procedimento pra inserir no fim_____________________________//

void inserir_fim (Nó **lista, int n){
    
    Nó *aux, *novo = malloc(sizeof(Nó)); // cria o nó novo e um auxiliar para percorrer
    
    if(novo){
        
        novo->valor = n;
        novo->prox = NULL;
        
        // é o pimeiro da lista?
        if(*lista == NULL){       // se a lista inicialmente estiver vazia: 
        
            *lista = novo;      //    insere como se fosse o primeiro item 
        }else{ // se ja tiver ao menos um elemento na lista                                                           
            
            aux = *lista;  // o auxiliar recebe os elementos da lista a partir do 1º
            while(aux->prox){ // enquanto o auxiliar tiver proximo != NULL
                
                aux = aux->prox; // o auxiliar recebe seu proximo elemento
                
            }aux->prox = novo; // não tendo próximos elementos, botamos o novo como próx
        }
    }else printf("Erro de alocação de memória");
    
}

//_____________________procedimento pra inserir ordenado______________________//

void inserir_ordenado(Nó **lista, int num){
    
    Nó *aux, *novo = malloc(sizeof(Nó));
    
    if(novo){
        
        novo->valor = num;
        // a lista está vazia?
        if(*lista ==NULL){
            novo->prox = NULL;    
            *lista = novo;
            
        }else if(novo->valor < (*lista)->valor){  // val é menor que todos osoutros da lista?
            
            novo->prox = *lista;
            *lista = novo;
        }else{
            
            aux = *lista;
            
            while(aux->prox && novo->valor > aux->valor){
                
                aux = aux->prox;
            }novo->prox = aux->prox;
            aux->prox = novo;
        }   
    }else printf("Erro de alocação de memória"); 
}

//____________________procedimento pra retirar do inicio_______________________//

//_____________________procedimento pra retirar do meio________________________//

//_____________________procedimento pra retirar do fim_________________________//






//_______________________________imprimindo______________________________//

void imprimir(Nó *nó){
    
   printf("\n \t Lista:"); 
    
    while(nó){ // enquanto o nó existir
    
    printf("%d, ", nó->valor); // printa o valor do nó
    
    nó = nó->prox; //percorre a lista
    }printf("\n\n\a");
   
}


//________________________________________________main_______________________________________________//
int main(){

 Nó *lista = NULL;
 int opção, valor, ant;

do{
    
    printf("\n\t Qual operação você quer efetuar com a lista?");
    printf("\n digite: ");
    printf("\n\n1 para inserir item no início\n2 para inserir no meio");
    printf("\n3 para inserir no final\n4 para insterir ordenado\n5 para ver a lista\n0 para sair\n ");
    
    scanf("%d", &opção);
    
    switch(opção){
        
    case 1: printf("\n Digite um valor:");
        scanf("%d ", &valor);
        insertInicio(&lista, valor);
        break;
        
    case 2: printf("\n Digite um valor:");
        scanf("%d", &valor);
        printf("\n Digite o numero anterior a esse valor na fila:");
        scanf("%d", &ant);
        inserir_meio(&lista, valor, ant);
        break;
        
    case 3: printf("\n Digite um valor:");
        scanf("%d ", &valor);
        inserir_fim(&lista, valor);
        break;
        
    case 4: printf("\n Digite um valor:");
        scanf("%d ", &valor);
        inserir_ordenado(&lista, valor);
        
        break;
    case 5: 
        imprimir(lista);
        break;
        
    default: printf("\n DIgite um número válido");    
        break;
    }
    
}while(opção != 0);


return 0;
}
