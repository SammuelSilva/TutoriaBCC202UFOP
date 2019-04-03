#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <cstring>

// #define INEXISTENTE -1;

Clientes* InicializaClientes(const string&, const string&, const string&, const string&, const string&, const string&);
Clientes** InicializaClientes(const int&);
void InsercaoDeClientes(Clientes* novo, Clientes* conjunto);
string RetornarCpf(Clientes* cliente);
void RemocaoDeClientes(Clientes* velho, Clientes* novo);
int BuscaCpf(string, Clientes**, const int&);


#endif
