#include <iostream>
#include <vector>
using namespace std;

struct resposta
{
    bool existe;
    vector<int> sublista;
};

resposta existe_sublista(int array[], int tamanho, int soma)
{
    //Aceita
    if (soma == 0) return {true, {}};
    //Rejeita
    if (soma < 0 || tamanho == 0) return {false, {}};
    //Chamadas recursivas
    resposta ans = existe_sublista(array ,tamanho - 1 ,soma - array[tamanho - 1]);
    if (ans.existe)
    {
        ans.sublista.push_back(array[tamanho - 1]);
    }
    else
    {
        ans = existe_sublista(array ,tamanho - 1 ,soma);
    }
    return ans;
}

int main()
{
    int N; cin >> N;
    int S; cin >> S;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    resposta r = existe_sublista(A, N, S);
    if (r.existe)
    {
        cout << "Esta e a sublista, de soma " << S << '.' << endl;
        cout << '[';
        for (unsigned int i = 0; i < r.sublista.size(); i++)
        {
            if (i == r.sublista.size() - 1) cout << r.sublista[i];
            else cout << r.sublista[i] << ", ";
        }
        cout << ']';
        cout << endl;
    }
    else
    {
        cout << "Não existe sublista de soma " << S << '.' << endl;
    }

    return 0;
}