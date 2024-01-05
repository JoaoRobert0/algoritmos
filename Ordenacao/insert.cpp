#include <iostream>
using namespace std;

int main()
{
    cout << "Digite cartas quantidade de cartas: ";
    int N;
    cin >> N;
    int cartas[N];

    cout << "Digite os numeros das cartas: ";
    for (int i = 0; i < N; i++)
    {
        cin >> cartas[i];
    }

    cout << "\n";

    cout << "Baralho na forma inicial: ";
    for (int i = 0; i < N; i++)
    {
        cout << cartas[i] << " ";
    }

    cout << "\n\n";

    //Insert sort
    for (int i = 1; i < N; i++)
    {
        int key = cartas[i];
        int j = i - 1;

        while (j >= 0 && cartas[j] > key)
        {
            cartas[j + 1] = cartas[j];
            j = j - 1;
        }
        cartas[j + 1] = key;
    }

    cout << "Baralho ordenado: ";
    for (int i = 0; i < N; i++)
    {
        cout << cartas[i] << " ";
    }

    return 0;
}