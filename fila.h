#ifndef FILA_H
#define FILA_H

#include <QString>

namespace minhaNamespace {
class Fila
{
private:
    int tamanho;
    int *vetor;
    int inicioFila;
    int fimFila;
    int quantidadeElementos;
public:
    Fila(int tamanho);
    ~Fila();

    bool estaVazia() const { return quantidadeElementos == 0; }
    bool estaCheia() const { return quantidadeElementos == tamanho; }
    int getQuantidadeElementos() const { return quantidadeElementos; }

    void inserir(int elemento);
    void retirar();
    int acessar() const;
    int acessar(int) const;
};
}

#endif // FILA_H
