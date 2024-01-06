#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int S; cin >> S;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    string existe = "NO";
    for (int i = 0; i < N; i++)
    {
        if (existe == "YES")
        {
            break;
        }
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] + A[j] == S)
            {
                existe = "YES";
                break;
            }
        }
    }

    cout << existe << endl;

    return 0;
}