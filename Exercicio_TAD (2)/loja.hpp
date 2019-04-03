#ifndef LOJA_HPP
#define LOJA_HPP

#include <iostream>
#include <cstring>

#include "item.hpp"
#include "cliente.hpp"
//#define INEXISTENTE -1;

using std::cin;
using std::cout;

Loja* CriaLoja(const int&);
bool InsercaoDeItens(Itens*, Loja*);//Retirar Loja
bool InsercaoDeClientes(Clientes*, Loja*);//Retirar Loja
bool RemocaoDeClientes(const string&, Loja*);
bool RemocaoDeItens(const string&, Loja*);

#endif
