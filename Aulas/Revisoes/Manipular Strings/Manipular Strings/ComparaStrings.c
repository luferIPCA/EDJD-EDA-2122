/*
	Name:  Modelo
	Author: oribeiro & lufer
	Description:
*/
#include <stdio.h>
#include <string.h>

// declara��o ou assinatura das fun��es locais
void indicaMaiorAlfabetica(char *frase1, char *frase2);

// fun��o principal
int main_2() {
	// declara��o e inicializa��o de vari�veis
    char frase1[20];
    char frase2[20];
    int opcao ;
    int comprimento;
	// dados de entrada
    printf("primeira frase? ");
    fgets(frase1,20,stdin);
    frase1[strlen(frase1)-1] = '\0'; // limpa \n

    printf("segunda frase? ");
    fgets(frase2,20,stdin);
    frase2[strlen(frase2)-1] = '\0';

    // mostrar os valores lidos
	printf("conte�do de frase1: [%s] tam=%d \n", frase1, strlen(frase1));
	printf("conte�do de frase2: [%s] tam=%d \n", frase2, strlen(frase2));

	// op��es para ordena��o
	printf("indicar maior palavra pelo:\n");
	printf("\t 1. comprimento \n");
    printf("\t 2. ordem alfab�tica \n");
    printf("op��o? ");
    scanf("%d",&opcao);

    switch (opcao) {
        case 1: // indicaMaiorComprimento(frase1, frase2);
                break;
        case 2: indicaMaiorAlfabetica(frase1, frase2);
                break;
        default:
            printf("op��o desconhecida.");
            break;
        }

	// c�lculos

	// resultados


	return 0;
}

// defini��o das fun��es

void indicaMaiorAlfabetica(char *frase1, char *frase2){
    int rc;
    char maior[20];

    rc = strcmp(frase1, frase2);
    if (rc == 0) {
        printf("[%s] � igual a [%s]\n",frase1, frase2);
    }else {
        if (rc < 0) {
            strncpy(maior, frase2, 20);
        } else { // rc > 0
            strncpy(maior, frase1, 20);
        }
        printf("maior palavra: %s \n", maior);
    }

}
