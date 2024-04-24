#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

struct Funcionario 
{
	int prontuario;
	string nome;
	double salario;
	Funcionario* prox;
};

Funcionario* inicia() 
{
	return NULL;
}

bool isEmpty(Funcionario* lista) 
{
	return (lista == NULL);
}

Funcionario* insere(Funcionario* lista, int prontuario, string nome, double salario) 
{
	Funcionario* novo = new Funcionario();
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = lista;
	return novo;
};

void printLista(Funcionario* lista) 
{
	Funcionario* aux;
	string line(20, '-');
	aux = lista;
	double totalSalarios = 0;
	if (isEmpty(lista)) 
	{
		cout << "Lista vazia. " << endl;
	}
	else 
	{
		cout << "Lista de funcion�rios: " << "\n"  << endl;
		cout << line << endl;
		while (aux != NULL) 
		{
			cout << "Prontu�rio: " << aux->prontuario << endl;
			cout << "Nome: " << aux->nome << endl;
			cout << "Sal�rio: " << aux->salario << endl;
			cout << line << endl;
			totalSalarios = totalSalarios + aux->salario;
			aux = aux->prox;
		}
		cout << "\n" << "Total de sal�rios: " << totalSalarios << endl;
		cout << "\n" << "Fim da lista." << endl;
	}
}

void printFuncionario(Funcionario* lista, int prontuario) 
{
	Funcionario* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario) 
	{
		aux = aux->prox;
	}
	if (aux) 
	{
		cout << "\n" << "Funcion�rio encontrado: " << endl;
		cout << endl;
		cout << "Prontu�rio: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Sal�rio: " << aux->salario << endl;
	}
	else 
	{
		cout << "\n" << "Funcion�rio n�o encontrado." << endl;
	}
}

Funcionario* find(Funcionario* lista, int prontuario) 
{
	Funcionario* aux;
	aux = lista;
	while (aux != NULL && aux->prontuario != prontuario) 
	{
		aux = aux->prox;
	}
	return aux;
}

Funcionario* remove(Funcionario* lista, int prontuario) 
{
	Funcionario* aux;
	Funcionario* ant = NULL;
	aux = lista;

	while (aux != NULL && aux->prontuario != prontuario) 
	{
		ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL) 
	{
		return lista;
	}

	if (ant == NULL) 
	{
		lista = aux->prox;
	}

	else 
	{
		ant->prox = aux->prox;
	}

	free(aux);
	return lista;
}

void freeLista(Funcionario* lista) 
{
	Funcionario* aux;
	aux = lista;
	while (aux != NULL) 
	{
		Funcionario* ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	Funcionario* listaFuncionarios;
	listaFuncionarios = inicia();
	int prontuario;
	string nome;
	double salario;
	int opcao;

	do 
	{
		string line(40, '-');
		cout << "0. Sair" << "\n";
		cout << "1. Incluir" << "\n";
		cout << "2. Excluir" << "\n";
		cout << "3. Pesquisar" << "\n";
		cout << "4. Listar" << "\n";
		cout << "Op��o: ";
		cin >> opcao;

		while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
		{
			cout << "Op��o inv�lida. Digite novamente" << endl;
			cout << "Op��o: ";
			cin >> opcao;
		}

		switch (opcao) 
		{
		case 0:
			cout << line << endl;
			cout << "Encerrando programa...\n";
			break;

		case 1:
			cout << line << endl;
			cout << "Digite o prontuario: ";
			cin >> prontuario;
			if (find(listaFuncionarios, prontuario)) {
				cout << "Funcion�rio j� cadastrado!\n";
				cout << line << endl;
				break;
			}
			cout << "Digite o nome: ";
			cin >> nome;
			cout << "Digite o salario: ";
			cin >> salario;
			listaFuncionarios = insere(listaFuncionarios, prontuario, nome, salario);
			cout << "Funcion�rio cadastrado com sucesso!" << endl;
			cout << line << endl;
			break;

		case 2:
			cout << line << endl;
			cout << "Digite o prontu�rio do funcion�rio a ser exclu�do: ";
			cin >> prontuario;
			listaFuncionarios = remove(listaFuncionarios, prontuario);
			cout << "Funcion�rio exclu�do com sucesso!" << endl;
			cout << line << endl;
			break;

		case 3:
			cout << line << endl;
			cout << "Digite o prontu�rio do funcion�rio a ser pesquisado: ";
			cin >> prontuario;
			printFuncionario(listaFuncionarios, prontuario);
			cout << line << endl;
			break;

		case 4:
			cout << line << endl;
			printLista(listaFuncionarios);
			cout << line << endl;
		}
	} 
	while (opcao != 0);

	freeLista(listaFuncionarios);

	return 0;
}