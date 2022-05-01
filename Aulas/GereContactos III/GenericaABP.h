/*****************************************************************//**
 * @file   GenericaABP.h
 * @brief  M�dulo gen�rico de �rvores Bin�rias de Procura
 * 
 * @author lufer
 * @date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>

#pragma region Genericas

/**
 * Dados.
 */
typedef struct Element {
	void* data;
}Element;


//Nodo da �rvore
typedef struct Node {
	Element element;				
	struct Node* leftTree;
	struct Node* rightTree;
}Node, * PtrNode;


//Inicializa uma �rvore
Node* InitTree();

//Cria novo nodo de uma �rvore bin�ria
Node* NewNode(void *e);
Node* AddNode(Node* root, void *e, int (*comp)(void *a,void *b));
void ShowTree(Node* root, void (*show)(void* data));

#pragma endregion


