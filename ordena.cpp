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
    }  catch (std::bad_alloc const&) {
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
{ // [5], [2], [3], [7] || [5],
    /*if(vetorOrdenado->estaVazia()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar();
    } // [5] - ordenado, [2], [3], [7] - aleatorio

    if(vetorAleatorio->acessar() < vetorOrdenado->acessar()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar(); // [5], [2] - ordenado, [3], [7] - aleatorio
        vetorOrdenado->inserir(vetorOrdenado->acessar());
        vetorOrdenado->retirar(); // [2], [5] - ordenado, [3] - aleatorio
    }*/

    //A [5], [2], [3], [7]
    //A  ||
    //O [2], [3], [5], [7]

    /*if(vetorOrdenado->estaVazia()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar();
    } //O [5], A [2], [3], [7]



    if(vetorAleatorio->acessar() < vetorOrdenado->acessar()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar();
        vetorAleatorio->inserir(vetorOrdenado->acessar());
        vetorOrdenado->retirar();
    } //O [2], A [3], [7] || [5]

    vetorOrdenado->inserir(vetorAleatorio->acessar());
    vetorAleatorio->retirar();
    //O (2 como topo) [2], [3], A  [7] || [5]
    //O  [3], A  [7] || [5], [2],
    //O ()*/

    if(vetorOrdenado->estaVazia()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar();
    }

    for(int i = 0; i < 24; i++){

        if(vetorAleatorio->acessar() < vetorOrdenado->acessar()) {
            vetorOrdenado->inserir(vetorAleatorio->acessar());
            vetorAleatorio->retirar();
        }

        /*if(vetorAleatorio->acessar() > vetorOrdenado->acessar()) {
            vetorOrdenado->inserir(vetorOrdenado->acessar());
            vetorOrdenado->retirar();
            vetorOrdenado->inserir(vetorAleatorio->acessar());
            vetorAleatorio->retirar();
        }*/

        if(vetorAleatorio->acessar() > vetorOrdenado->acessar()) {
            vetorAleatorio->inserir(vetorOrdenado->acessar());
            vetorOrdenado->retirar();
            vetorOrdenado->inserir(vetorAleatorio->acessar());
            vetorAleatorio->retirar();
        }

        if(vetorAleatorio->estaVazia()) return;
    }
}

QString Ordena::getVetorOrdenado() const
{
    if(vetorOrdenado->estaVazia()) return "";

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

    if(vetorAleatorio->estaVazia()) return "";

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
/*if(vetorOrdenado->estaVazia()){
    vetorOrdenado->inserir(vetorAleatorio->acessar());
    vetorAleatorio->retirar();
    // [5] - ordenado, [2], [7] - aleatorio
}

for(int i = 0; i < vetorAleatorio->getQuantidadeElementos(); i++){
    if(vetorAleatorio->acessar() > vetorOrdenado->acessar()){
        vetorOrdenado->inserir(vetorAleatorio->acessar());
        vetorAleatorio->retirar();
    } else{

    }
}

if(vetorOrdenado->estaVazia()){ // primeira operação - vetor vazio
    vetorOrdenado->inserir(vetorAleatorio->acessar());
    vetorAleatorio->retirar();
}

if(vetorAleatorio->acessar() >= vetorOrdenado->acessar()){ // segunda operação - vetor com 1 termo
    vetorOrdenado->inserir(vetorAleatorio->acessar());
}

if(vetorAleatorio->acessar() < vetorOrdenado->acessar()){ // (else) segunda operação - vetor com 1 termo
    vetorOrdenado->inserir(vetorAleatorio->acessar());
    vetorOrdenado->inserir(vetorOrdenado->acessar());
    vetorOrdenado->retirar();
}

if(vetorAleatorio->acessar() >= vetorOrdenado->acessar()){
    vetorOrdenado->inserir(vetorAleatorio->acessar());
    vetorOrdenado->inserir(vetorOrdenado->acessar());
    vetorOrdenado->retirar();
    vetorOrdenado->retirar();
}*/
