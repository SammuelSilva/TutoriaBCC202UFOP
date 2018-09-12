//*****************************************************************************************************************//
/*

TAD PROFESSOR/DISCIPLINA, Contem erros, favor consertar antes de enviar para amanda
NAO COPIEM 100%, entendam o código... Porque se não, quem se fode é vocês;


*/

#include <iostream>
#include <cstring>
#include "Aloca.hpp"
#include "Professor.hpp"
#include "Disciplina.hpp"

using namespace std;

//Definicao da Struct Aloca
struct Aloca{
	Professor* professor;
	Disciplina** disciplina;
	int cargadidatica;
	int vetorposicao;
};

//Cria ponteiro de ponteiro do tipo aloca
Aloca** CriarVetorAloca(int tamanho){
	return new Aloca[tamanho];
}

//Cria ponteiros de professor, disciplina , e inicia cargadidatica e vetorposicao
Aloca* CriarAlocar(){
	int auxiliar = 4;
	Aloca* aux = new Aloca;
	aux->professor=CriaProfessor();
	aux->disciplina = CriarVetorDisciplina(auxiliar);
	for(int i=0; i<4; i++){
		aux->disciplina[i]=CriaDisciplina();
	}
	aux->cargadidatica=16;
	aux->vetorposicao=0;
	return aux;
}

//Deletar ponteiros
Aloca* LiberarAlocacao(Aloca* aloca){
	LiberarProfessor(aloca->professor);
	for(int i=0; i<aloca->vetorposicao; i++){
		LiberarDisciplina(aloca->disciplina[i]);
	}
	LiberarDisciplina(aloca->disciplina);
	delete aloca;
}

Aloca* LiberarAlocacao(Aloca** aloca){
	delete[] aloca;
}

//Verifica se oprofessor ja esta alocado
bool Checagem(Aloca *aloca, Professor *professor, int& contador){
 	for(int i=0; i<contador; i++){
 		if(checagem(aloca[i]->professor, professor)){
 			return true;
 		}
 	}

 	return false;
}

//Busca a siape do professor, se encontrar retorna o indice
 int BuscaSiape(Aloca **aloca, Professor *professor, int& contador){
 	for(int i=0; i<contador; i++){
 		if(checagem(aloca[i]->professor, professor)){
 			return contador;
 		}
 	}

 	return -1;
}

//Imprime o vetor de aloca
void imprimir (Aloca *aloca){
	cout << endl;
	imprimir(aloca->professor);
	for(int i=0; i<aloca->vetorposicao; i++){
		imprimir(aloca->disciplina, i);
	}
}

//Remove uma alocaçao feita
void RemoverAlocacao(Aloca *aloca, Aloca *proximoaloca){
	RemoverProfessor(aloca->professor, proximoaloca->professor);
	for(int i=0; i<4; i++){
		RemoverDisciplina(aloca->disciplina[i], proximoaloca->disciplina[i]);
	}
	aloca->cargadidatica=proximoaloca->cargadidatica;
	aloca->vetorposicao=proximoaloca->vetorposicao;
}

//Copia os dados de professor para o vetor de aloca
void CopiaProfessor(Aloca *aloca, Professor *professor){
	copia(aloca->professor, professor);
}

//Remove o professor
void RemoveProfessor(Aloca *aloca, Aloca *proximoaloca){
	aloca->professor = proximoaloca->professor;
	for(int i=0; i<4; i++){
		aloca->disciplina[i]=proximoaloca->disciplina[i];
	}
	aloca->cargadidatica=proximoaloca->cargadidatica;
	aloca->vetorposicao=proximoaloca->vetorposicao;

}
//copia a disciplina
bool CopiaDisciplina(Aloca *aloca, Disciplina *disciplina){
	int aux = aloca->vetorposicao;
	if(RetornaChecagem(disciplina, aloca->cargadidatica)){
		CopiaDisciplinas(aloca->disciplina[aux], disciplina);
		aloca->vetorposicao++;
		return true;
	}else{
		return true;
	}
}

//Verifica se o professor tem vaga para adicionar disciplinas
void ChecagemProfessorDisciplina(Aloca *aloca, string& aux){
	int auxiliar;
	for(int i=0; i<aloca->vetorposicao; i++){
		auxiliar=BuscarDisciplina(aloca->disciplina[i], aux, i);
		if(auxiliar!=-1){
			aloca->cargadidatica+=IncrementaCargaDidatica(aloca->disciplina[auxiliar]);
			if(i+1<aloca->vetorposicao){
				for(int j=auxiliar; j<aloca->vetorposicao-1; j++){
					RemoverDisciplina(aloca->disciplina[j], aloca->disciplina[j+1]);
				}
				aloca->vetorposicao++;
				break;
			}else{
				aloca->vetorposicao--;
				break;
			}
		}
	}
}

//busca disciplinas
bool BuscarDisciplina (Aloca *aloca, string codigo){
	int auxiliar;
	for(int i=0; i<aloca->vetorposicao; i++){
		auxiliar=BuscarDisciplina(aloca->disciplina[i], codigo, i);
		if(auxiliar!=-1){
			aloca->cargadidatica+=IncrementaCargaDidatica(aloca->disciplina[auxiliar]);
			cout << "CARGA HORARIA RESTANTE: " << aloca->cargadidatica << " HORAS" << endl;
			for(int j=auxiliar; j<aloca->vetorposicao-1; j++){
				RemoverDisciplina(aloca->disciplina[j], aloca->disciplina[j+1]);
			}
			aloca->vetorposicao--;
			return true;
		}
	}
	return false;
}

//Altera o professor
void AlteraProfessorCadastrado(Aloca *aloca, string *nome){
	AlteraProfessor(aloca->professor, nome);
}

//Altera a disciplina
void AlteraDisciplina(Aloca *aloca, string *nome, int *cargahoraria, int *opcao, string *codigo){
	for(int i=0; i<aloca->vetorposicao; i++){
		if(BuscarDisciplina(aloca->disciplina[i], *codigo, i)>-1){
			AlteraDisciplina(aloca->disciplina[i], nome, cargahoraria, opcao);
			return 202;
		}
	}
}
