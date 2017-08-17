#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

void rez(int n, int B[])
{
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << '\t' << B[i] << '\n';
    }
}
int main ()
{
    int n, m;
    bool A[10][10];
    ifstream in ("U3_2.txt");
    in >> m >> n;
    for (int i=0; i<n; i++)
        for (int j = 0; j<n; j++)
            in >> A[i][j];

    in.close();

    int B[n] = {0}, room = 1;
    B[0] = room;

    for (int i = 1; i < n; i++)
    {
        for (int j=0; j < n; j++)
        {
            if (i!=j && !A[i][j] && B[j] == 0)
                B[j] = i+1;
            else if (B[j] == 0)
            {
                room++;
                B[j] = room;
            }

        }
    }
    if (room>m)
        cout << "Sprendinys neegzistuoja\n";
    else
        rez(n, B);
return 0;
}
