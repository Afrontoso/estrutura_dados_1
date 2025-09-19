#include <stdio.h>

int main()
{
    char nome[100001]; 
    char sigla[4];
    int count = 0;
    int limite;
    
    scanf("%s", nome);
    scanf("%s", sigla);
    
    
    if (sigla[2] == 'X'){
        limite = 2;
    }else{
        limite = 3;
    }
    
    for (int i = 0; nome[i] != '\0' && count < limite; i++)
    {
        if (nome[i] - 32 == sigla[count])
        {
            count++;
        }
    }

    if (count == limite)
    {
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }

    return 0;
}
