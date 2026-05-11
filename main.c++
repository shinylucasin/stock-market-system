#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Item {
    int quant;
    double preco;
    Item *next;
};

queue<Item*> filaCompras;
Item *start = NULL;
Item *ending = NULL;

void comprar (int quant, double preco){
    Item *novo = new Item; // anotação pra quem for fazer a alocação de memoria
    novo->preco = preco;   // não sei se new e malloc podem ser usados juntos
    novo->quant = quant;   // talvez tenha q mudar o new (linha 18) e o delete (linha 44) ☻♥SS
    novo->next = NULL;

    if (ending == NULL) {
        start = novo;
        ending = novo;
    } 
    else {
        ending->next = novo;
        ending = novo;
    }
    filaCompras.push(novo);
}

void vender (int quantVenda){

    while (quantVenda>0 && !filaCompras.empty()) {

        Item *pedidos = filaCompras.front();

        if(pedidos->quant <= quantVenda){

            quantVenda -= pedidos->quant;
            filaCompras.pop();
            start = start->next;
            delete pedidos;

            if (start == NULL) {
                ending = NULL;
            }
        }
        else{
            pedidos->quant -= quantVenda;
            quantVenda = 0;
        }
    }
}

int main (){

    return 0;
}