#include <stdio.h>
#include <string.h>
/*Imprimir na saída padrão o 
nome da banda e o 
ano que a música pesquisada foi lançada, 
respeitando o formato [nome do show] : ano [número do ano], onde os campos [nome do show] e [número do ano] 
devem ser substituídos pelos seus respectivos valores que estão armazenados na lista de shows. 
Caso uma determinada banda não esteja cadastrada, você deve imprimir a mensagem 
Banda nao cadastrada.*/

struct tipoBanda {
    char nome[80];
    int ano;
};

struct tipoShow {
    char nome[80];
    int qtd;
    struct tipoBanda bandas[100];
};

void pesquisarNomeBanda(char pesquisa[80], struct tipoShow shows[50], int n){

    int encontrou = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < shows[i].qtd; j++){
            if(!strcmp(pesquisa, shows[i].bandas[j].nome)){
                printf("%s : ano %d\n", shows[i].nome, shows[i].bandas[j].ano);
                encontrou++;
            }
        }
    }
    if(encontrou == 0) printf("Banda nao cadastrada\n");
}