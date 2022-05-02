/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief �rvore Bin�ria de Procura  (ABP)
 *
 * Metodos para manipular uma �rvore Bin�ria de Procura de Pessoas
 * @bug No known bugs.
*/
#include "Contatos.h"
#include "Pessoa.h"
#include "GenericaABP.h"
#include  <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//Inicia �rvore
	Node* historico = InitTree();

	Contacto* c1 = CriaContacto("Telef", "253123321");
	ListaContactos* contactos = NULL;
	contactos = InsereContactoListaContactos(contactos, c1);
	MostraContactos(contactos);

	Pessoa* p = CriaPessoa("PP", 12345);
	ListaPessoa* inicio = NULL;
	inicio = InserePessoaListaPessoas(inicio, p);

	Pessoa* p2 = CriaPessoa("JJ", 4321);
	inicio = InserePessoaListaPessoas(inicio, p2);
	MostraTodasPessoas(inicio);

	inicio = InsereContactoPessoa(inicio, c1, 12345);

	p = CriaPessoa("CC", 1);
	inicio = InserePessoaListaPessoas(inicio, p);

	p = CriaPessoa("DD", 13345);
	inicio = InserePessoaListaPessoas(inicio, p);

	Contacto* c2 = CriaContacto("Email", "aaa@bbb.pt");
	inicio = InsereContactoPessoa(inicio, c2, 4321);

	MostraContactosPessoa(inicio, 12345);
	MostraContactosPessoa(inicio, 4321);

	SavePessoas(inicio, "Pessoas.dat");
	SaveAll(inicio, "All.dat");

	MostraTodasPessoas(inicio);

	inicio = NULL;	//ATEN��O: n�o � suficiente NULL...deve destruir-se a lista
	inicio = GetAllPessoas("Pessoas.dat");
	inicio = GetAll("All.dat", inicio);

	puts("\nAp�s Ficheiro\n");
	MostraTodasPessoas(inicio);

	//Gere Historico
	inicio = RemovePessoaABP(inicio, 12345, &historico);
	puts("\nAp�s Remo��o (I)\n");
	MostraTodasPessoas(inicio);
	puts("\nHist�rico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa

	inicio = RemovePessoaABP(inicio, 1, &historico);
	puts("\nAp�s Remo��o (II)\n");
	MostraTodasPessoas(inicio);
	puts("\nHist�rico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa

}