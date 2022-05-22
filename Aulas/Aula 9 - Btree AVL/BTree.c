/*
lufer@ipca.pt

Implementa��o de �rvores Bin�rias de Procura
*/
#include <stdio.h>
#include "btree.h"

/*
Inicia uma �rvore Bin�ria de Procura
*/
PtrNode InitTree() {
	return NULL;
}

/*
Cria Nodo de uma �rvore
*/
PtrNode NewNode(Element e) {
	PtrNode node = (PtrNode)malloc(sizeof(Node));
	if (node == NULL) return NULL;	//problemas ao criar espa�o em mem�ria	
	node->element = e;
	node->leftTree = NULL;
	node->rightTree = NULL;
	return node;
}


/*
Cria Nodo de uma �rvore Generalizada - Informa��o desacoplada!
H2
*/
PtrNodeII NewNodeGeneral(Element e) {
	PtrNodeII node = (PtrNodeII)malloc(sizeof(NodeII));
	if (node = NULL) return NULL;	//problemas ao criar espa�o em mem�ria
	if (node->element = (Element *)malloc(sizeof(Element)) == NULL) {
		free(node);
		return NULL;
	}	
	*node->element = e;
	node->leftTree = NULL;
	node->rightTree = NULL;
	return node;
}


/*
Destroy Nodo de �rvore
*/
void DestroyNode(Node **p) {		//DestroyNode(PtrNode *p)	
	if (*p != NULL) {
		free(*p);	
		*p = NULL;
		//H2
		//free((*p)->element);
		//*p = NULL;
	}
}

/*
Calcula o N�mero de Nodos de uma �rvore
*/
int TreeSize(PtrNode r) {

	if (r == NULL) return 0;
	else
		return (1 + TreeSize(r->leftTree) + TreeSize(r->rightTree));
}

/*
Calcula a Altura de uma �rvore
*/
int TreeHeight(PtrNode root) {
	unsigned int leftHeight, rightHeight;
	if (root == NULL) return 0;
	else
	{
		leftHeight = TreeHeight(root->leftTree);
		rightHeight = TreeHeight(root->rightTree);
		return (Max(leftHeight, rightHeight) + 1);
		//ou
		//return (1+Max(TreeHeight(root->leftTree), TreeHeight(root->rightTree)));		
	}

}


// =========== Opera��es de procura ============

/*
Procura um elemento num �rvore!
*/
PtrNode FindNode(Element e, PtrNode root) {
	if (root == NULL) return NULL;
	if (root->element.val == e.val) return root;
	else
	{
		if (root->element.val > e.val) return (FindNode(e, root->leftTree));
		else return (FindNode(e, root->rightTree));
	}
}


/*
Verifica se determinado elemento existe: IMPLEMENTAR
*/
Boolean ExistNode(Element e, PtrNode root){}

/*
Determina o maior elemento da �rvore: IMPLEMENTAR
*/
PtrNode GetMax(PtrNode root) {
	if (root == NULL) return NULL;
	if (root->rightTree == NULL)  
		return root;
	else
		return GetMax(root->rightTree);
}


/*
Determina o menor elemento da �rvore: IMPLEMENTAR
*/
PtrNode GetMin(PtrNode root){
	if (!root) return NULL;
	if (root->leftTree == NULL)
		return root;
	else
		return GetMin(root->leftTree);
}

// =========== Opera��es de Manipula��o ============

/*
Divide e Conquista Algoritmo
*/
void DoSomethingToAllNodes(struct Node *root) 
{
	if (root) {
		//DoSomeThingTo(root);
		DoSomethingToAllNodes(root->leftTree);
		DoSomethingToAllNodes(root->rightTree);
	}
}


/*
Insere Nodo da �rvore
*/
PtrNode AddNode(PtrNode root, Element e) {
	if (root == NULL)		//arvore vazia
	{
		root = NewNode(e);		
	}
	else
	{
		if (root->element.val > e.val) {		//Insere � esquerda
			root->leftTree = AddNode(root->leftTree, e);
		}
		else
			if (root->element.val < e.val)		//Insere � direita
				root->rightTree = AddNode(root->rightTree, e);
			else
			{ 
				//j� existe, n�o insere!
			}
	}
	return root;
}

//H2
void AddNodeII(PtrNode *root, Element e) {
//void AddNodeII(Node **root, Element e) {
	if (*root == NULL) return;
	if ((*root)->element.val > e.val) {
		AddNodeII(&(*root)->leftTree, e);
	}
	else
		AddNodeII(&(*root)->rightTree, e);
}

/*
Remove Nodo da �rvore
*/
PtrNode DeleteNode(PtrNode root, Element e) {
	if (root == NULL) return NULL;	//�rvore vazia ou enexistente
	if (root->element.val > e.val)
		root->leftTree = DeleteNode(root->leftTree, e);
	else
		if (root->element.val < e.val) {
			root->rightTree = DeleteNode(root->rightTree, e);
		}
		else    //(root->element.val == e.val) 
		{
			root = DeleteCurrentNode(root);
		}
	return root;
}

/*
Apaga Nodo. Refaz �rvore
*/
PtrNode DeleteCurrentNode(PtrNode root) {
	PtrNode aux;
	if (root == NULL) return NULL;	//Nada para apagar!

	if (root->leftTree == NULL && root->rightTree == NULL) {	//�nico nodo
		DestroyNode(&root);
		return NULL;
	}
	else 
		if (root->leftTree==NULL){		//s� tem sub-arvore direita...ligar � direita
			aux = root;
			root = root->rightTree;
			DestroyNode(&aux);
		}
		else
		{
			if (root->rightTree == NULL) {	//s� com sub-arvore esquerda
				aux = root;
				root = root->leftTree;
				DestroyNode(&aux);
			}
			else       //com sub-arvores esquerda e direita
			{
				//substitui pelo menor da sub-arvore direita
				root->element = FindMin(root->rightTree)->element;
				//elimina o menor da sub-arvore direita
				root->rightTree = DeleteNode(root->rightTree, root->element);
			}
		}
	return root;
}

/*
Identico ao GetMin
*/
PtrNode FindMin(PtrNode root) {
	if (root->leftTree == NULL) return root;
	else
		return(FindMin(root->leftTree));
}


void PreOrder(PtrNode root) {
	if (root == NULL) return;
	printf("Val=%d\n", root->element.val);
	PreOrder(root->leftTree);
	PreOrder(root->rightTree);
}

void PosOrder(PtrNode root){
	if (root == NULL) return;
	PosOrder(root->leftTree);
	PosOrder(root->rightTree);
	printf("Val=%d", root->element.val);	
}

void InOrder(PtrNode root){
	if (root == NULL) return;
	InOrder(root->leftTree);
	printf("Val=%d", root->element.val);
	InOrder(root->rightTree);
	
}


// =========== Balanceamento ============

/*
Prepara Balanceamento da arvore
*/
PtrNode Balance(PtrNode root) {
	PtrNode newRoot=NULL;
	if (root == NULL) return NULL;

	int tot = TreeSize(root); //quantos nodos tem a arvore?
	int count = 0;

	//criar estrutura din�mica auxiliar
	Node *listNode;

	if ((listNode = (Node *)malloc(sizeof(Node)*tot))==NULL) return NULL;
	//preenche lista a partir da arvore
	BST2List(root, &count, listNode);
	//balanceia arvore
	newRoot = BSTBalance(newRoot,listNode, 0, tot - 1);
	free(listNode);
	return newRoot;
}

/*
Balanceia �rvore. Travessia Bin�ria de um array!
*/
PtrNode BSTBalance(PtrNode root, Node *list, int ini, int end) {
	unsigned int m;

	if (ini <= end) {
		m = (ini + end) / 2;
		root = AddNode(root, list[m].element);
		root = BSTBalance(root,list, ini, m - 1);
		root = BSTBalance(root, list, m+1, end);
	}
	return root;
}

/*
Cria uma Lista a partir dos elementos de uma arvore
*/
void BST2List(PtrNode root, unsigned int *count, Node *list) {
	if (root != NULL) {
		BST2List(root->leftTree, count, list);
		list[(*count)++].element = root->element;
		BST2List(root->rightTree, count, list);
	}
}

/*
Mostrar uma �rvore
*/
void Show(PtrNode root, int nivel) {
	unsigned int i;
	if (root == NULL) {
		for (i = 0; i < nivel; i++) printf("\t");
		printf("*\n");
		return;
	}
	Show(root->rightTree, nivel + 1);
	for (i = 0; i < nivel; i++) printf("\t");
	printf("%d\n", root->element.val);
	Show(root->leftTree, nivel + 1);
}

/*
Exerc�cio Folha 8
Parsing a uma string com express�o em pre-order

*/
Exp* Parse(char v[], int i) {
	char o;
	Exp *aux=NULL;

	if (i < sizeof(v)) {
		o = v[i];
		aux = (PtrNode)malloc(sizeof(Node));
		aux->val = o;		
		if ((o == '+') || (o == '-')) {
			aux->oper = o;
			aux->dir = Parse(v, ++i);
			aux->esq = Parse(v, ++i);
		}
	}
	return aux;
}