#include "ordena.h"

namespace minhaNamespace {

Ordena::Ordena(int tamanho):
    vetorOrdenado(0),
    vetorAleatorio(0),
    tamanho(0)
{
    if(tamanho < 1) throw QString("O tamanho do vetor não pode ser < 1!");
    this->tamanho = tamanho;
    try {
        vetorOrdenado = new Fila(tamanho);
        vetorAleatorio = new Fila(tamanho);
    }  catch (std::bad_alloc) {
        throw QString("Erro na alocação de memória!");
    }
}

Ordena::~Ordena() {
    if(vetorOrdenado) delete vetorOrdenado;
    if(vetorAleatorio) delete vetorAleatorio;
}

void Ordena::gerarValoresEInserir()
{
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++) {
        int valor = rand() % 1000 + 1;

        vetorAleatorio->inserir(valor);
    }
}

void Ordena::ordenarVetor()
{

}

QString Ordena::getVetorOrdenado() const
{
    QString res = "";

    for(int i = 0; i < tamanho; i++) {
        res += "[ ";
        res += QString::number(vetorOrdenado->acessar(i));
        res += " ]";
        if(i < tamanho - 1) res += ", ";
    }

    return res;
}

QString Ordena::getVetorAleatorio() const
{
    QString res = "";

    for(int i = 0; i < tamanho; i++) {
        res += "[ ";
        res += QString::number(vetorAleatorio->acessar(i));
        res += " ]";
        if(i < tamanho - 1) res += ", ";
    }

    return res;
}

}
