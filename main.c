#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct livro{
        char nome[50];
        char isbn[50];
        float preco;
        int score; 
        char editora[50]; 
    };
        typedef struct livro* pLivro;
    
   pLivro pLivro_aloc(int qtde){
        pLivro livros = (pLivro)malloc(qtde * sizeof(struct livro));
        return livros;
    } // alocar memoria 



    void livro_ler(pLivro livros, int qtde){
        int i;
      
        for(i = 0; i<qtde; i++){
            scanf(" %[^\n]", livros[i].nome);
            scanf(" %[^\n]", livros[i].isbn);
            scanf("%f", &livros[i].preco);
            scanf("%d", &livros[i].score);
            scanf(" %[^\n]", livros[i].editora);
        }
    
    
    }// insira os dados de qtde livros

    void livro_imprime(pLivro livros , int qtde){
        int i;
        for( i = 0; i< qtde; i++){
            
            printf("Livro %d:\n", i +1);
            printf("Nome: %s\n", livros[i].nome);
            printf("ISBN: %s\n", livros[i].isbn);
            printf("Preço: R$ %.2f\n", livros[i].preco);
            printf("Score: %d\n", livros[i].score);
            printf("Editora: %s\n", livros[i].editora);

            printf("\n");
        }
        
    }

    void livro_desaloca(pLivro livros){
        free(livros);
    } // liberar memoria 

    int main(){

        int quantidade; 

        scanf("%d", &quantidade);
            if(quantidade<=0){
                printf("Sem livros\n"); 
                return 0;
            }

        pLivro livros = pLivro_aloc(quantidade);
        livro_ler(livros, quantidade); 
        livro_imprime(livros, quantidade);
        livro_desaloca(livros);
        return 0;
    }
   
