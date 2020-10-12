#include <stdio.h> 
#include <stdlib.h>
#define TAM 10

#include "camila.c"


int menu();

void dobrar(int *x);

int menu(){
    int op;
    printf("\nDigite as opcao desejada\n");
    printf("0 - Sair\n"); 
    printf("1 - Cadastrar Estrutura Auxiliar\n"); 
    printf("2 - Inserir\n"); 
    printf("3 - Excluir ultimo elemento\n"); 
    printf("4 - Excluir um numero no vetor\n"); 
    printf("5 - Listar uma estrutura\n"); 
    printf("6 - Listar todas as estruturas\n"); 
    printf("7 - Listar estrutura ordenada\n"); 
    printf("8 - Listar todas estruturas ordenadas\n");
    printf("9 - Aumentar estrutura auxiliar\n");
    printf("10 - Dobrar \n");
    scanf("%d", &op);
    return op;
}

int main(){
	
    inicializar();
    
    FILE *file;
    file = fopen ("trabalho3_camila.txt", "r+"); //Abre um arquivo texto para leitura e gravação. O arquivo deve existir e pode ser modificado.
    
    int i, j, tamanho, valor_arquivo, quantidade, posicao;
    
    if (file == NULL){
    	printf("Sem arquivo para leitura\n Sera criado um novo arquivo! \n");
    	file = fopen ("trabalho3_camila.txt", "w"); // Abrir um arquivo texto para gravação. Se o arquivo não existir, ele será criado. Se já existir, o conteúdo anterior será destruído.

	} 
	else {
		printf("O arquivo foi aberto com sucesso!\n");
		
		for (i=0;i<TAM;i++){ //tamanho
			fscanf(file, "%d;", &valor_arquivo);
			vetorPrincipal[i+1].tamanho = valor_arquivo; 
		}
		
		for (i=0; i<TAM; i++){
			
			fscanf(file,"%d;", &valor_arquivo);
			vetorPrincipal[i+1].quantidade = valor_arquivo;
			 tamanho = vetorPrincipal[i+1].tamanho;
       		 vetorPrincipal[i+1].ponteiro = (int *)malloc (tamanho * sizeof (int));
		}
		
		for(i=0; i<TAM; i++){
			quantidade = vetorPrincipal[i+1].quantidade;
			fscanf (file, "%d;", &posicao);

			for(j=0; j<quantidade; j++){
				fscanf(file, "%d;", &vetorPrincipal[posicao].ponteiro[j]);

			}	
			
		}	
	}
    
	fclose(file);	

	
			
    int op;
    int sair = 0;
    int ret;
    
    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair =1;
                salvar_Dados();
                finalizar();
                break;
            }
            
            case 1:{ //Cadastrar Estrutura Auxiliar
               
                
                int posicao, tamanho, ret;
                
                
                printf("Digite a posicao: \n");
                scanf ("%d", &posicao);
                
                printf("Digite o tamanho da estrutura: \n");
                scanf ("%d", &tamanho);
                
                              
                
				ret = criarEstruturaAuxiliar(tamanho, posicao);
				
				if (ret == SUCESSO){
                	printf("Estrutura criada com sucesso");
                }else if (ret == POSICAO_INVALIDA){
                	printf("Digite valor entre 1 e 10! \n");
                }else if (ret == TAMANHO_INVALIDO){
                	printf("Digite um tamanho valido! \n");	
                }
                else if (ret =  JA_TEM_ESTRUTURA_AUXILIAR){
                	printf("Ja existe estrutura criada! \n ");
				}
				else if(ret = SEM_ESPACO_DE_MEMORIA){
					printf("Sem espaco de memoria! \n ");
				}
                break;
                
            }
            
            case 2:{ //inserir
                //TODO
                
                int posicao, valor, ret;
                                
                printf("Digite a posicao: \n");
                scanf ("%d", &posicao);
                
                printf("Digite o valor a ser inserido: \n");
                scanf ("%d", &valor);
                
                ret = inserirNumeroEmEstrutura(valor, posicao);
                if (ret == SUCESSO){
                	printf("Inserido com sucesso");
                }else if (ret == SEM_ESPACO){
                	printf("Sem EspaÃ§o");
                }else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	printf("Sem estrutura Auxiliar");	
                }
                break;
            }

            case 3:{ //excluir ultimo elemento
            
           		int posicao, ret;
           		
                printf("Digite a posicao: \n");
                scanf("%d", &posicao);
                
                ret = excluirNumeroDoFinaldaEstrutura(posicao);
                
    
                if (ret == SUCESSO){
                	printf("Excluido com sucesso");
                }
				else if (ret == POSICAO_INVALIDA){
                	printf("Posicao invalida");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR){
                	printf("Sem estrutura Auxiliar");	
                }
                else if (ret == ESTRUTURA_AUXILIAR_VAZIA){
                	printf("Estrutura vazia");	
                }
 				break;

			}
          
            case 4:{ // Excluir um numero no vetor
            
            	int ret, posicao, valor;
            
	            printf("Digite de qual posicao do elemento a ser excluido \n");
	            scanf("%d", &posicao);
	            
	            printf("Digite o valor que deseja excluir: \n");
	            scanf("%d", &valor);
            
             	ret = excluirNumeroEspecificoDeEstrutura(valor, posicao);
            
                if (ret == POSICAO_INVALIDA){
                    printf ("Posicao invalida\n");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar\n!");							
				}
				else if (ret == ESTRUTURA_AUXILIAR_VAZIA){
					printf ("Estrutura vazia!\n");
				}
				else if (ret == SUCESSO){
					printf ("Excluido com sucesso\n");
				}
				else 
					printf ("Numero inexistente! \n");
				break;
            }
            

            case 5:{ //Listar dados de uma estrutura
                int posicao, retorno;
                
                printf("Qual a estrutura a ser listada (1..10)? \n");
                scanf("%d", &posicao);
                
                int qtd =  getQuantidadeElementosEstruturaAuxiliar(posicao);
                
                if (qtd == POSICAO_INVALIDA){
                    printf ("Posicao invalida");
                }
				else if (qtd == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar!");							
				}
				else if (qtd == ESTRUTURA_AUXILIAR_VAZIA){
					printf ("Estrutura vazia!");
					
				                    
                }else{ // existe elemento
                    int vetorAux[qtd];
                
                    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
                    
                    if (retorno == SUCESSO){
                        //imprimir para os dados para o usuÃ¡rio
                        int i = 0;
                        for (; i < qtd; i++){
                            printf ("%d |", vetorAux[i]);
                            
                        }
                    }                        
                }
                break;
            }
            
            case 6:{ // Listar todas as estruturas
 				
 				int ret;
 				
 				int i = 0;
 				
 				ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
 				
 				if (ret == POSICAO_INVALIDA){
                    printf ("Posicao invalida");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar!");							
				}
				
				else if (ret == SUCESSO){
					printf ("\nRecuperado com sucesso os valores da estrutura! \n");
				}	
 				
				for (i = 0; i < 10; i++){
			    	printf ("%d |", vetorAux[i]);
			    }
				break;
			 }
            
            case 7:{ //Listar estrutura ordenada
            	int posicao, ret;
                
                printf("Qual a estrutura a ser ordenada (1..10)? \n");
                scanf("%d", &posicao);
                
            	ret = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);
            	
           	
            	int qtd =  getQuantidadeElementosEstruturaAuxiliar(posicao);
            	int i = 0;
				for (i = 0; i < qtd; i++){
			    	printf ("%d |", vetorAux[i]);
			    }
            	
            	if (ret == POSICAO_INVALIDA){
                    printf ("Posicao invalida");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar!");							
				}
				
				else if (ret == SUCESSO){
					printf ("\nRecuperado com sucesso os valores da estrutura! \n");
				}
				
            	
				break;
			}
			
			case 8:{ //Listar todas estruturas ordenadas
				int ret;
 				
 				int i = 0;
 				
 				ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
 				
 				if (ret == POSICAO_INVALIDA){
                    printf ("Posicao invalida");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar!");							
				}
				
				else if (ret == SUCESSO){
					printf ("\nRecuperado com sucesso os valores da estrutura! \n");
				}	
 				
				for (i = 0; i < 10; i++){
			    	printf ("%d |", vetorAux[i]);
			    }
				break;
			}
            
            
            case 9:{ //aumentar tamanho estrutura
            
             	int ret, posicao, novoTamanho;
             	
             	printf ("Digite qual estrutura deseja aumentar: \n");		
                scanf("%d", &posicao);
                
            	printf ("Digite valor adicional para aumento da estrutura \n");		
                scanf("%d", &novoTamanho);
                
                ret = modificarTamanhoEstruturaAuxiliar(posicao, novoTamanho);
               
			    if (ret == POSICAO_INVALIDA){
                    printf ("Posicao invalida");
                }
				else if (ret == SEM_ESTRUTURA_AUXILIAR) {
					printf ("Sem estrutura auxiliar!");							
				}
				else if (ret == NOVO_TAMANHO_INVALIDO){
					printf ("Novo tamanho invalido!"); 
				}	
				else if (ret == SUCESSO){
					printf ("Aumento realizado\n");
				}
				else{
					printf ("SEM_ESPACO_DE_MEMORIA\n");
				}
					
                
                break;
            }

            
            case 10:{ //dobrar
                //ler um numero
                int valor;
                
                printf ("Informe um valor \n");
                scanf("%i", &valor);
                
                dobrar(&valor);
                
                //passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)
                
                printf("%i", valor);
                
                break;
            }
           
		   case 11:{ //dobrar
                criarEstruturaAuxiliar(1, 1);
                criarEstruturaAuxiliar(2, 2);
                criarEstruturaAuxiliar(3, 3);
                criarEstruturaAuxiliar(4, 4);
                criarEstruturaAuxiliar(5, 5);
                criarEstruturaAuxiliar(6, 6);
                criarEstruturaAuxiliar(7, 7);
                criarEstruturaAuxiliar(8, 8);
                criarEstruturaAuxiliar(9, 9);
                criarEstruturaAuxiliar(10, 10);
   				inserirNumeroEmEstrutura(5, 1);
    			inserirNumeroEmEstrutura(8, 2);
    			inserirNumeroEmEstrutura(9, 2);
                
                printf("cadastrado valor default");
                
                break;
            } 
            
            
            default:{
                printf("opcao invÃ¡lida\n");
            }

            
        }
        
        
    }
    
    return 0;
    
}
