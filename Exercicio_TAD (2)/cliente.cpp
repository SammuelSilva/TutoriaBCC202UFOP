#include "cliente.hpp"

struct Clientes{
  string nome;
  string data_nascimento;
  string cpf;
  string endereco;
  string telefone;
  char sexo;
};

Clientes* InicializaClientes(const string& nome, const string& data_nascimento, const string& cpf, const string& endereco, const string& telefone, const char& sexo){
  Clientes* cliente        = new Clientes;
  cliente->nome            = nome;
  cliente->data_nascimento = data_nascimento;
  cliente->cpf             = cpf;
  cliente->endereco        = endereco;
  cliente->telefone        = telefone;
  cliente->sexo            = sexo;
  return new Clientes;
}

Clientes** InicializaClientes(const int& quantidade){
  new Clientes*[quantidade];
}

void InsercaoDeClientes(Clientes* novo, Clientes* conjunto){
    conjunto = novo;
}

string RetornarCpf(Clientes cliente){
    return cliente.cpf;
}

void RemocaoDeClientes(Clientes* velho, Clientes* novo){
  velho = novo;
}

int BuscaCpf(string cpf, Clientes* conjunto, const int& quantidade){
  for(int cliente = 0; cliente < quantidade; cliente++){
    if(conjunto[cliente]->cpf == cpf)
      return cliente;
  }

  return -1;
}
