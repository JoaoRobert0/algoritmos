#include <iostream>
using namespace std;

bool labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c);

int main()
{
    int linha, coluna, labirinto[20][20];
    cin >> linha >> coluna;

    //Preenchendo labirinto
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            cin >> labirinto[i][j];
        }
    }

    cout << bool(labirinto_bt(labirinto, linha, coluna, 0, 0)) << endl;

    return 0;
}

bool labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c)
{
    //Rejeita
    if (l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] == 1)
    {
        return false;
    }

    //Aceita
    if (l == linha - 1 && c == coluna - 1)
    {
        return true;
    }

    //Caminho para baixo
    if (labirinto_bt(labirinto, linha, coluna, l + 1, c))
    {
        return true;
    }

    //Caminho para direita
    if (labirinto_bt(labirinto, linha, coluna, l, c + 1))
    {
        return true;
    }

    //Final
    return false;

}