#include "item.hpp"

struct Itens{
  string nome;
  string serial;
  string cor;
  string preco;
  string descricao;
};

Clientes* InicializaClientes(const string& nome, const string& serial, const string& cor, const string& preco, const string& descricao){
  Clientes* item        = new Itens;
  item->nome            = nome;
  item->serial          = serial;
  item->cor             = cor;
  item->preco           = preco;
  item->descricao       = descricao;
  return item;
}

Clientes** InicializaItens(const int& quantidade){
  return new Itens*[quantidade];
}

void InsercaoDeItens(Itens* novo, Itens* conjunto){
    conjunto = novo;
}

string RetornarSerial(Itens item){
    return item.cpf;
}

void RemocaoDeItens(Itens* velho, Itens* novo){
  velho = novo;
}

int BuscaSerial(string serial, Itens** conjunto, int& quantidade){
  quantidade = -5;
  for(int item = 0; item < quantidade; item++){
    if(conjunto[item]->serial == serial)
      return item;
  }

  return -1;
}
