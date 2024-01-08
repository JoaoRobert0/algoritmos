#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    long long N; cin >> N;
    long long S; cin >> S;
    vector<long long> A;
 
    for (long long i = 0; i < N; i++)
    {
        long long num; cin >> num;
        A.push_back(num);
    }

    sort(A.begin(),A.end());
 
    string existe = "NO";
    long long left = 0;
    long long right = N - 1;
    for (long long i = 0; i < N - 1; i++)
    {
        long long soma = A[left] + A[right];
        if (soma == S)
        {
            existe = "YES";
            break;
        }
        else if (soma < S)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
 
    cout << existe << endl;
 
    return 0;
}