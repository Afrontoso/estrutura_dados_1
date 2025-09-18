#include <stdio.h>

int main()
{

    char nome[100];
    char sobrenome[100];
    int i = 0;
    int ultimoNome = -1;

    scanf("%s", nome);
    scanf(" %[^\n]", sobrenome);

    while (sobrenome[i] != '\0')
    {
        if (sobrenome[i] == ' ')
        {
            ultimoNome = i;
        }
        i++;
    }

    printf("%s.", nome);

    for (i = ultimoNome + 1; sobrenome[i] != '\0'; i++)
    {
        printf("%c", sobrenome[i]);
    }

    printf("@unb.br\n");
    return 0;
}