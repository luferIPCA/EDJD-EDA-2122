/*
	Name:  Modelo
	Author: oribeiro & lufer
	Description:
*/
#include <stdio.h>
#include <string.h>
// declara��o ou assinatura das fun��es locais

// fun��o principal
int main_1() {
	// declara��o e inicializa��o de vari�veis
    char a[5] = {'L', 'P', '1', '\0'};
    char b[15] = "Ling Prog 1";
    char c[15] = "LP1\0AED";
    char d[15];

    int comprimento;
	// dados de entrada

	// c�lculos
    // atribuir o conte�do de b a d
     // d = b; // errado: seria a atribui��o dos endere�os
     strncpy(d, b, 15);
     // alterar d para LP2
     d[10] = '2';

    // calcular comprimento da string
    comprimento = strlen(c); // "string length" definida em string.h

    // comparar uma string (ordem lexicogr�fica / Alfab�tica)
    // funcao strcmp "string compare"

	// resultados
    //printf("conte�do de a: [%s] (endere�o %d) *a = %c\n", a, a, *a);
    printf("conte�do de b: [%s] \n",b );
    printf("conte�do de c: [%s] comprimento: %d \n", c, comprimento );
    printf("conte�do de d: [%s] \n",d );

	return 0;
}

// defini��o das fun��es
/* procedimento (fun��o que n�o devolve nada, tipo void)
    para testar a fun��o strcmp de string.h
    */
void testaComparacao(char *lesq, char *ldir){
    int rc; // resultado da compara��o

    // strcmp "string compare" (definida em string.h)
    // permite comparar (ordem alfab�tica) duas strings, devolvendo:
    //   < 0 : a primeira aparece primeiro (menor) do que a segunda
    //   == 0: s�o iguais
    //   > 0 : a primeira aparece depois (maior) do que a segunda

    rc = strcmp(lesq, ldir);
    if (rc < 0) {
        printf("[%s] aparece primeiro (menor) do que  [%s]", lesq, ldir);
    } else if (rc == 0) {
        printf("[%s] � igual a [%s]", lesq, ldir);
    } else { // rc > 0
        printf("[%s] aparece depois (maior) do que  [%s]", lesq, ldir);
    }

}

