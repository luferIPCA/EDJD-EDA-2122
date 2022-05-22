/*
�rvores AVL - Adelson,�Velski�&�Landis
lufer@ipca.pt
*/
#include "btree.h"

#ifndef AVLTREE
#define AVLTREE

// ================== AVL Tree ================
/*
AVL Tree - Adelson,�Velski�&�Landis
*/

typedef struct AVLNode {
	Element val;
	struct avlNode *esq, *dir;
	unsigned int height;		
}AVLNode;

typedef AVLNode *PtrAVLNode;

// =============== M�TODOS ================
unsigned int AVLHeight(PtrAVLNode root);
unsigned int BF(PtrAVLNode root);
PtrAVLNode BalanceAVL(PtrAVLNode root);
//calcular n�mero de elementos
//mostrar a �rvore
//Valor no nodo X
//Destruir a �rvore
//Maior elemento
//Menor elemento
//Travessias
#endif