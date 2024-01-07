#include <iostream>
using namespace std;

int existe_sublista(int array[], int tamanho, int soma);

int main()
{
    int N; cin >> N;
    int S; cin >> S;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << existe_sublista(A, N, S) << endl;

    return 0;
}

int existe_sublista(int array[], int tamanho, int soma)
{
    //Rejeita
    if (soma < 0 || tamanho == 0) return 0;
    //Aceita
    if (soma == 0) return 1;
    //Chamadas recursivas
    return existe_sublista(array ,tamanho - 1 ,soma - array[tamanho - 1]) || existe_sublista(array, tamanho - 1, soma);
}