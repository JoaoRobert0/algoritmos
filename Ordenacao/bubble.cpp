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

    cout << "\n";

    cout << "Lista original: ";
    for (int i = 0; i < N; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    cout << "Lista ordenada crescente: ";
    for (int i = 0; i < N; i++)
    {
        cout << vetor[i] << " ";
    }

    return 0;  
}