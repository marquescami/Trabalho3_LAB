
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAMAUX 50


#include "EstruturaVetores.h"

struct vetor{
       int tamanho;
       int quantidade;
       int *ponteiro;
} vetorPrincipal[TAM];

int vetorAux[TAMAUX];

void dobrar(int *x){

    *x = *x * 2;
    
    


}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
	int retorno = 0;
	
	if (posicao < 1 || posicao>10){
    	retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
    	 return retorno;
	}    
    
    else if (tamanho < 1){
    	retorno = TAMANHO_INVALIDO;  // o tamanho nao pode ser menor que 1
    	  return retorno;
	}
    	
    	
	else if (vetorPrincipal[posicao].ponteiro != NULL){
		retorno = JA_TEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
		return retorno;
    }
    
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		vetorPrincipal[posicao].tamanho = tamanho;
        vetorPrincipal[posicao].ponteiro = (int *)malloc (tamanho * sizeof (int));
        retorno = SUCESSO; 
		return retorno;
	}

		        
	else {
		retorno = SEM_ESPACO_DE_MEMORIA;     // o tamanho ser muito grande
		return retorno;		
	}

	
	
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

	int retorno = 0;
	int controle = vetorPrincipal[posicao].quantidade;
	
	
		if (posicao < 1 || posicao>10){
    		retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
    		return retorno;
		}
	    if (vetorPrincipal[posicao].tamanho == 0){
			retorno = SEM_ESTRUTURA_AUXILIAR;
			//printf("Sem estrutura Auxiliar \n");
			return retorno;
		}	        
		else if (controle < vetorPrincipal[posicao].tamanho){
			vetorPrincipal[posicao].ponteiro[controle] = valor;
   			vetorPrincipal[posicao].quantidade++;
   			retorno = SUCESSO;
			//printf("INCLUIDO \n");
   			return retorno;
	   	}
	   	else {
	   		retorno = SEM_ESPACO;
			//printf("Sem ESPACO \n");
			return retorno;
		}	
	
	
	
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
	
	int retorno = 0;
	
	if (posicao < 1 || posicao>10){
    	retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
	}    
	
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
    }
    
    else if (vetorPrincipal[posicao].quantidade == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;    // a posicao pode já existir estrutura auxiliar
    }
    else {
    	
    	 vetorPrincipal[posicao].quantidade--;
    		retorno = SUCESSO;
	}
   
  return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar 
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar *

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
	
	int retorno = 0;
	int i=0;
	int j; 
	int quantidade_elementos = vetorPrincipal[posicao].quantidade;
	
	
	if (posicao < 1 || posicao>10){
    	return POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
	}    
     		
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		return SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
    }
    
    else if (vetorPrincipal[posicao].quantidade == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;    // a posicao pode já existir estrutura auxiliar
    }
    else{
    	for(i=0;i<quantidade_elementos;i++){
    		if (valor == vetorPrincipal[posicao].ponteiro[i]) break;    			
        }
        
	    if(valor == vetorPrincipal[posicao].ponteiro[i]){
	    	vetorPrincipal[posicao].quantidade--;
	    	for (j=i; j<quantidade_elementos; j++){
	    		vetorPrincipal[posicao].ponteiro[j] = vetorPrincipal[posicao].ponteiro[j+1]; 
	    	}
				return SUCESSO;
		}
		else {
			return NUMERO_INEXISTENTE;
		}	           	 
	
	}  	
    	


}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	int retorno = 0;
	int i;

	if (posicao < 1 || posicao>10){
    	retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
	}    
     		
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
    }
    
    else {
    	    
		for (i = 0; i < vetorPrincipal[posicao].quantidade; i++){	
    		vetorAux[i] = vetorPrincipal[posicao].ponteiro[i];
		}				
		retorno = SUCESSO;	
	}			
    return retorno;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
	int quantidade = vetorPrincipal[posicao].quantidade;
    
	if (posicao < 1 || posicao>10){
		retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
		return retorno;
	}    
 		
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		retorno =  SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
		return retorno;
	}
	
	// ORDENACAO
	int k, j, aux;
	
	for (k = 0; k < quantidade; k++) {
		vetorAux[k] = vetorPrincipal[posicao].ponteiro[k];
    }

    for (k = 1; k < quantidade; k++) {

        for (j = 0; j < quantidade - 1; j++) {

            if (vetorAux[j] > vetorAux[j + 1]) {
                aux          = vetorAux[j];
                vetorAux[j]     = vetorAux[j + 1];
                vetorAux[j + 1] = aux;
               
            }
        }
    }
     retorno = SUCESSO;
     return retorno;
}


 






/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	
	int k, i, qtd, j, retorno = 0, tem_estrutura = 0, tam=0, m=0;
	
	for (k = 0; k < TAM; k++) {
		if(vetorPrincipal[k].quantidade>0){
			tem_estrutura = 1;
			break;
		}
    }
    if(tem_estrutura==0){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    	return retorno;
	}

    for(i=0;i<TAM;i++){
    	tam=tam+vetorPrincipal[i].quantidade;
    }

    *vetorAux = *(int *)malloc (tam * sizeof (int));

    for(i=0;i<TAM;i++){
        qtd=vetorPrincipal[i].quantidade;
        for(j=0;j<qtd;m++,j++){
        	vetorAux[m]= vetorPrincipal[i].ponteiro[j];
		}
    	
	}
	 
     retorno = SUCESSO;
     return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

	int k, i, qtd, j, aux, retorno = 0, tem_estrutura = 0, tam=0, m=0;
	
	for (k = 0; k < TAM; k++) {
	
		if(vetorPrincipal[k].quantidade > 0){
			tem_estrutura = 1;
			break;
		}
    }
	
    if(tem_estrutura==0){
    
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    	return retorno;
	}

    for(i=0;i<TAM;i++){
    	tam=tam+vetorPrincipal[i].quantidade;
    }

    *vetorAux = *(int *)malloc (tam * sizeof (int));

    for(i=0;i<TAM;i++){
        qtd=vetorPrincipal[i].quantidade;
        for(j=0;j<qtd;m++,j++){
        	vetorAux[m]= vetorPrincipal[i].ponteiro[j];
		}
    	
	}
	
	// ORDENACAO
    for (k = 1; k < tam; k++) {

        for (j = 0; j < tam - 1; j++) {

            if (vetorAux[j] > vetorAux[j + 1]) {
                aux          = vetorAux[j];
                vetorAux[j]     = vetorAux[j + 1];
                vetorAux[j + 1] = aux;
               
            }
        }
    }
	 
     retorno = SUCESSO;
     return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar * 
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar *
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo *
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    int retorno = 0;
    int tamanho = vetorPrincipal[posicao].tamanho + novoTamanho;
	
	if (posicao < 1 || posicao>10){
    	retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
    	return retorno;
	}    
     		
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		retorno =  SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
		return retorno;
    }
    
   	else if (novoTamanho < 1){
		retorno = NOVO_TAMANHO_INVALIDO;    
		return retorno;
    }

    else{
    	vetorPrincipal[posicao].ponteiro = (int *)realloc (vetorPrincipal[posicao].ponteiro, tamanho * sizeof (int));
    	vetorPrincipal[posicao].tamanho = tamanho;
    }
   
 	return SUCESSO;
    	    
    
}



/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
	int retorno = 0;
	
	if (posicao < 1 || posicao>10){
    	retorno = POSICAO_INVALIDA;    	  // se posição é um valor válido {entre 1 e 10}
    	return retorno;
	}    
     		
	else if (vetorPrincipal[posicao].ponteiro == NULL){
		retorno = SEM_ESTRUTURA_AUXILIAR;    // a posicao pode já existir estrutura auxiliar
		return retorno;
    }
    
    else if (vetorPrincipal[posicao].quantidade == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;    // a posicao pode já existir estrutura auxiliar
		return retorno;
    }
    else {
		retorno = vetorPrincipal[posicao].quantidade;
		return retorno;
	}

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){

    return NULL;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){


}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
   

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
   
   	int i;
	   	
   	for (i=0;i<TAM;i++) {
		vetorPrincipal[i].tamanho=0;
        vetorPrincipal[i].quantidade=0;
        vetorPrincipal[i].ponteiro=NULL; 
	
	}
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
	
	int i;
	for(i=0;i<TAM;i++){
		free(vetorPrincipal[i].ponteiro);
	}    
}


void salvar_Dados(){
	
	FILE *file;
    file = fopen ("trabalho3_camila.txt", "w");
    
    int i, j;
    char separador= ';', quebra_de_linha='\n';
    
    for (i=0; i<TAM; i++){  //salvando o tamanho 
    	fprintf(file, "%d", vetorPrincipal[i+1].tamanho);
    	fprintf(file, "%c", separador);
	}
		fprintf(file, "%c", quebra_de_linha);
		
	for (i=0; i<TAM; i++){  //salvando quantidade e separando
    	fprintf(file, "%d", vetorPrincipal[i+1].quantidade);
    	fprintf(file, "%c", separador);
    }
   	 fprintf(file, "%c", quebra_de_linha);
   	
	for(i=0;i<TAM; i++){
   		if(vetorPrincipal[i].quantidade!=0){ 
   			fprintf(file, "%d", i); 
			fprintf(file, "%c", separador); 
			
			for(j=0; j<vetorPrincipal[i].quantidade; j++){
				fprintf(file, "%d", vetorPrincipal[i].ponteiro[j]); //copiando dados das estruturas
				fprintf(file, "%c", separador); 
				
				
			}
	fprintf(file, "%c", quebra_de_linha);	  	
		}
	
	} 
	
	
	
	fclose(file);	
	
}
