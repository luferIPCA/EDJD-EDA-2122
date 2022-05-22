/*
�rvores Bin�rias de Procura - (Binary Search Tree )
lufer@ipca.pt

*/

//#pragma once
#ifndef BTREE
#define BTREE

#define Max(x,y)  ((x>y)? (x) : (y))

typedef   enum Boolean { false, true }   Boolean;

//Valor do nodo de uma �rvore - Elemento
typedef struct Element {
	int val;
} Element;


//H1: Nodo da �rvore
typedef struct Node {
	Element element;			//struct	
	struct Node *leftTree;
	struct Node *rightTree;
}Node;

typedef Node *PtrNode;


//===========================================================
//H2: Nodo da �rvore generalizado - informa��o desacoplada!
typedef struct NodeII {
	Element *element;			//apontador para struct
	struct NodeII *leftTree;
	struct NodeII *rightTree;
}NodeII;
typedef NodeII *PtrNodeII;
//===========================================================

//================= Assinatura de m�todos ===================

//Inicializa uma �rvore
PtrNode InitTree();

//Cria novo nodo de uma �rvore bin�ria
PtrNode NewNode(Element e);

//Destroi um nodo de uma �rvore
void DestroyNode(PtrNode *p);

//Calcula o N�mero de Nodos de uma �rvore
int TreeSize(PtrNode r);

//Calcula a Altura de uma �rvore
int TreeHeight(PtrNode r);

// =========== Opera��es de procura ============

PtrNode FindNode(Element e, PtrNode root);

Boolean ExistNode(Element e, PtrNode root);

PtrNode GetMax(PtrNode root);

PtrNode GetMin(PtrNode root);


// =========== Opera��es de Manipula��o ============

PtrNode AddNode(PtrNode root, Element e);
PtrNode DeleteNode(PtrNode root, Element e);
PtrNode DeleteCurrentNode(PtrNode root);
PtrNode FindMin(PtrNode root);

void PreOrder(PtrNode root);
void PosOrder(PtrNode root);
void InOrder(PtrNode root);

void Show(PtrNode root, int nivel);

// =========== Balanceamento ============

PtrNode Balance(PtrNode root);
PtrNode BSTBalance(PtrNode root,Node *list, int ini, int end);
void BST2List(PtrNode root, unsigned int tot, Node *list);


//Folha de Exercicios 10
struct Exp {
	char oper;		//operador: '+', '-', '*', '/'
	float val;		//valor do operando
	struct Exp *esq, *dir;
};

typedef struct Exp Exp;


#endif