#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <cstring>

Itens* InicializaItens(const string&, const string&, const string&, const string&, const string&, const string&);
Itens** InicializaItens(const int&);
void InsercaoDeItens(Itens* novo, Itens* conjunto);
string RetornarSerial(Itens* item);
void RemocaoDeItens(Itens* velho, Itens* novo);
int BuscaSerial(string, Itens**, int&);


#endif
