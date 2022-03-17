#ifndef ORDENA_H
#define ORDENA_H

#include <fila.h>
#include <stdlib.h>
#include <time.h>

namespace minhaNamespace {
class Ordena
{
    Fila *vetorOrdenado;
    Fila *vetorAleatorio;
    int tamanho;
public:
    Ordena(int tamanho);
    ~Ordena();

    void gerarValoresEInserir();
    void ordenarVetor();

    QString getVetorOrdenado() const;
    QString getVetorAleatorio() const;
};
}

#endif // ORDENA_H
