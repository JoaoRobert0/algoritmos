#include <iostream>
using namespace std;

int main()
{
    cout << "Digite o tamanho do vetor:" << endl;
    int N; cin >> N;

    int A[N];

    cout << "Digite os valores do vetor:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << "Digite a soma desejada:" << endl;
    int S; cin >> S;

    cout << endl;

    bool existe = false;
    for (int i = 0; i < N; i++)
    {
        if (existe == true) break;

        for (int j = i; j < N; j++)
        {
            int soma = 0;

            for (int k = i; k <= j; k++)
                soma += A[k];

            if (soma == S)
            {
                existe = true;
                break;
            }
        }
    }

    cout << existe << endl;

    return 0;
}