/**
* lufer
* Fun��es de 2a Ordem
* Fun��es recebem fun��es como par�metro
* Apontadores para fun��es
* (type) (*pointerName)(parameter);  
*   type: tipo que a fun��o retorna;
*   pointerName: apontador para a fun��o;
*   parameter: lista de par�metros passados para a fun��o
*/

#include "Funcoes.h"

//EXEMPLOS:
// g � apontador para uma fun��o que recebe um inteiro e devolve um inteiro 
//int (*g)(int a); 

/**
* Exemplo de fun��o que recebe um inteiro e devolve um inteiro
*/
int Dobro(int x) {
    return x * 2;
}

float Media(int x[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += x[i];
    }
    return (soma / n);
}

int Factorial(int x) {
    if (x == 0) return 1;
    else
        return (x * Factorial(x - 1));
}

/**
* @brief: Fun��o que recebe como par�metro um apontador para fun��o....
*/
int VariasFuncoes(int (*g)(int a))
{
    // Chama a fun��o apontada por g
    return g;
}