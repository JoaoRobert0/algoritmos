// Joãozinho está terminando seu primeiro semestre na faculdade e em uma das matérias ele que irá decidir sua nota, baseada nas notas das N provas que ele fez durante o semestre. A nota final de um aluno é baseada na média aritmética de 3 notas distintas. Mas Joãozinho não está preocupado em saber qual a maior nota final obtida, e sim qual a K-ésima maior nota final que pode ser obtida. É garantido que existe a K-ésima nota e lembre-se, é possível ter mais de uma nota final com o mesmo valor e elas devem ser consideradas distintas.

// Input
// A entrada contém não mais que 10 casos de teste e termina com EOF.

// A primeira linha de um caso de teste contém dois inteiros N e K (3 ≤ N ≤ 50, 1 ≤ K ≤ (N × (N - 1) × (N - 2))÷ 6).

// A segunda linha contém N inteiros Ai (1 ≤ Ai ≤ 105) representando a nota obtida na i-ésima prova.

// Output
// A saída deve conter um número de ponto flutuante formatado com uma casa decimal.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N, K;
    while (cin >> N >> K)
    {
        int A[N];
    
        //Lendo o vetor de notas
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        int indice = 0;
        double Medias[((N * (N - 1) * (N - 2)) / 6)]; //Formula para calcular todas as medias
        
        //Calculando todas as medias com 3 notas
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = i + 1; j < N - 1; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    Medias[indice] = (A[i] + A[j] + A[k]) / 3.0;
                    indice++;
                }
            }
        }

        //Ordenando de forma decrescente
        for (int i = 0; i < ((N * (N - 1) * (N - 2)) / 6) - 1; i++)
        {
            int max = i;
            for (int j = i + 1; j < (N * (N - 1) * (N - 2)) / 6; j++)
            {
                if (Medias[max] < Medias[j])
                {
                    max = j;
                }
            }
            double aux = Medias[max];
            Medias[max] = Medias[i];
            Medias[i] = aux;
        }

        //Exibindo a K-esima media
        for (int i = 0; i < (N * (N - 1) * (N - 2)) / 6; i++)
        {
            if (i == K - 1)
            {
                cout << setprecision(1) << fixed << Medias[i] << endl;
            }
        }
    }

    return 0;
}