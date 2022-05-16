/*
Manipular Tabelas de Hash
lufer
2022
*/

#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "hash.h"

int main() 
{	
	setlocale(LC_ALL, "Portuguese");

	printf("Hash(Maria)=%d\n", Hash("Maria"));
	printf("Hash(Maria Jo�o)=%d\n", Hash("Mario"));


	// ===================== GERIR HASH ===================
	{
		//Iniciar Hash Table
		IniciaHash(hashTable,MAX);
		//ou
		//*hashTable = IniciaHashII(hashTable);

		*hashTable = InsertValHash("Lu�s Vaz de Cam�es", hashTable);
		
		NodePtr novo1 = NewNode("Fernando Pessoa");
		*hashTable = InsertNodeHash(novo1, hashTable);
		//ou
		//InsertNodeHashVoid(novo1, hashTable);	

		ShowHash(hashTable);

		NodePtr novo2 = NewNode("E�a de Queiroz");
		//*hashTable = InsertNodeHash(novo2, hashTable);
		InsertNodeHashVoid(novo2, hashTable);

		NodePtr novo3 = NewNode("M�rio Zambujal");
		//*hashTable = InsertNodeHash(novo3, hashTable);
		InsertNodeHashVoid(novo3, hashTable);

		ShowHash(hashTable);

		NodePtr aux = FindNode("M�rio Zambujal", hashTable);
		ShowNode(aux);


		NodePtr novo4 = NewNode("Agostinha Bessa Lu�s");
		*hashTable = InsertNodeHash(novo4, hashTable);

		NodePtr novo5 = NewNode("Jos� Saramago");
		*hashTable = InsertNodeHash(novo5, hashTable);
		novo5 = NewNode("Jos� Saramago");
		InsertNodeHashVoid(novo5, hashTable);
		/*
		InsertNodeHashVoid(novo5, hashTable);
		InsertNodeHashVoid(novo5, hashTable);
		*/
		ShowHash(hashTable);


		*hashTable = Cleanup(hashTable);
		ShowHash(hashTable);
	}
}