#include "loja.hpp"

struct Loja{
  Itens* itens;
  Clientes* clientes;
  int quantidade_clientes;
  int quantidade_itens;
};

Loja* CriaLoja(const int& Quantidade){
  Loja NovaLoja;
  NovaLoja->itens               = new Itens[Quantidade];
  NovaLoja->clientes            = InicializaClientes(Quantidade);
  NovaLoja.quantidade_itens    = 0;
  NovaLoja.quantidade_clientes = 0;
  return NovaLoja;
}

bool InsercaoDeItens(Itens* dados, Loja* loja){//Retirar Loja
  if (BuscaSerial(dados->serial, loja->itens, loja->quantidade_itens) != -1)
    loja->itens[loja->quantidade_itens] = dados;
  else
    return false;

  return true;
}

bool InsercaoDeClientes(Clientes* dados, Loja* loja){//Retirar Loja
  if (BuscaCpf(RetornarCpf(dados), loja->clientes, loja->quantidade_clientes) != -1)
    InsercaoDeClientes(loja->clientes[loja->quantidade_clientes], dados);
  else
    return false;

  return true;
}

bool RemocaoDeClientes(const string& cpf, Loja* loja){
  int memoria = BuscaCpf(cpf, loja->clientes, loja->quantidade_clientes);

  if ( memoria != -1)
    loja->clientes[memoria] = loja->clientes[loja->quantidade_clientes-1];
  else
    return false;

  return true;
}

bool RemocaoDeItens(const string& serial, Loja* loja){
  int memoria = BuscaSerial(serial, loja->itens, loja->quantidade_itens);

  if ( memoria != -1)
    RemocaoDeItens(loja->itens[memoria], loja->itens[loja->quantidade_itens-1]);
  else
    return false;

  return true;
}
