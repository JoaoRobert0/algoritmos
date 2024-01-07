#include <iostream>
#include <iomanip>
using namespace std;

struct item
{
    int peso;
    double valor;
};

double mochila_bt(item itens[], int Tamanho, int Cap)
{
    if (Cap < 0 || Tamanho == 0) return 0;
    double c1 = 0;
    if (itens[Tamanho - 1].peso <= Cap)
    {
        c1 = itens[Tamanho - 1].valor 
        + mochila_bt(itens, Tamanho - 1, Cap - itens[Tamanho - 1].peso);
    }
    double c2 = mochila_bt(itens, Tamanho - 1, Cap);
    return c1 > c2 ? c1 : c2;
}

int main()
{
    int N; cin >> N;
    int Cap; cin >> Cap;
    
    item Itens[N];

    for (int i = 0; i < N; i++)
    {
        cin >> Itens[i].peso;
        cin >> Itens[i].valor;
    }

    cout << fixed << setprecision(2);
    cout << mochila_bt(Itens, N, Cap) << endl;
}
