#include <iostream>
using namespace std;

int main()
{
    cout << "Digite o tamanho do vetor: ";
    int N;
    cin >> N;
    int vetor[N];

    cout << "Digite os elementos do vetor: ";
    for (int i = 0; i < N; i++)
    {
        cin >> vetor[i];
    }

    cout << "Lista original: ";
    for (int i = 0; i < N; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "\n";

    int min, aux;
    for (int i = 0; i < N - 1; i++) //Até o penultimo elemento pois o ultimo estara ordenado
    {
        min = i; //Menor começa na posição inicial do laço
        for (int j = i + 1; j < N; j++)
        {
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }

    cout << "Lista ordenada crescente: ";
    for (int i = 0; i < N; i++)
    {
        cout << vetor[i] << " ";
    }
    return 0;
}