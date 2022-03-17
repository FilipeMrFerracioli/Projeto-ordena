#include "fila.h"

namespace minhaNamespace {

Fila::Fila(int tamanho):
    tamanho(0),
    vetor(0),
    inicioFila(0),
    fimFila(0),
    quantidadeElementos(0)
{
    if(tamanho <= 0) throw QString("Tamanho <= 0!");

    try {
        vetor = new int[tamanho];
        this->tamanho = tamanho;
    }  catch (std::bad_alloc) {
        throw QString("Erro na alocação de memória!");
    }
}

Fila::~Fila(){
    if(vetor) delete[] vetor;
}

void Fila::inserir(int elemento){
    if(estaCheia()) throw QString("Fila cheia!");

    if(estaVazia()) {
        inicioFila = fimFila = 0;
        vetor[fimFila] = elemento;
        quantidadeElementos++;
        return;
    }

    fimFila++;

    if(fimFila == tamanho) fimFila = 0;

    vetor[fimFila] = elemento;

    quantidadeElementos++;

    return;
}

void Fila::retirar(){
    if(estaVazia()) throw QString("Fila vazia!");

    if(inicioFila == fimFila) {
        inicioFila = fimFila = -1;
        quantidadeElementos = 0;
        return;
    }

    inicioFila++;

    if(inicioFila == tamanho) inicioFila = 0;

    quantidadeElementos--;
}

int Fila::acessar() const{
    if(estaVazia()) throw QString("Fila vazia!");

    return vetor[inicioFila];
}

int Fila::acessar(int elemento) const{
    if(estaVazia()) throw QString("Fila vazia!");

    return vetor[elemento];
}

}
