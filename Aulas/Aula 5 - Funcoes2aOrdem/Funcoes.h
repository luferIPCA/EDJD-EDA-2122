/*****************************************************************//**
 * @file   Funcoes.h
 * @brief  
 * Fun��es de 2a Ordem
 * Fun��es recebem fun��es como par�metro
 * Apontadores para fun��es
 * (type) (*pointerName)(parameter);
 *   type: tipo que a fun��o retorna;
 *   pointerName: apontador para a fun��o;
 *   parameter: lista de par�metros passados para a fun��o
 * @author lufer
 * @date   April 2022
 *********************************************************************/
#pragma once


//Assinaturas comuns: 
int Dobro(int x);		// Dobro � fun��o que devolve um int
float Media(int x[], int n);
int Factorial(int x);

/**
* @brief: Assinatura de fun��o que recebe como par�metro um apontador para fun��o....
*/
int VariasFuncoes(int (*g)(int a));

//EXEMPLOS:
// g � apontador para uma fun��o que recebe um inteiro e devolve um inteiro 
//int (*g)(int a); 
