#include <iostream>
using namespace std;

int sublista_csm(int Array[], int N)
{
    int soma_max = Array[0];

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int soma = 0;
            for (int k = i; k < j; k++)
            {
                soma += Array[k];
                if (soma > soma_max)
                {
                    soma_max = soma;
                }
            }
        }
    }

    return soma_max;
}

int main()
{
    int N; cin >> N;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << sublista_csm(A, N);
}