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
    //Aceita
    if (soma == 0) return 1;
    //Rejeita
    if (soma < 0 || tamanho == 0) return 0;
    //Chamadas recursivas
    int r1 = existe_sublista(array ,tamanho - 1 ,soma - array[tamanho - 1]);
    int r2 = existe_sublista(array, tamanho - 1, soma);
    return r1 + r2;
}