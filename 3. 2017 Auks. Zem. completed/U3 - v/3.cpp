#include <iostream>
#include <locale>
#include <fstream>
#include <cmath>

using namespace std;

int n;

bool fibonacci(int w)
{
    if (abs(sqrt(5*w*w+4) - int(sqrt(5*w*w+4))) < 0.0001 ^ abs(sqrt(5*w*w-4) - int(sqrt(5*w*w-4))) < 0.0001)
        return true;
    return false;
}
void disp(int A[])
{
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i*n+j];
            if (fibonacci(A[i*n+j]) || A[i*n+j]==1)
                cout << '*';
            cout << '\t';
        }
        cout << '\n';
    }
}

void alg(int A[])
{
    A[int(n/2)*n+int(n/2)] = 1;
    int currentI = int(n/2);
    int currentJ = int(n/2);
    char dir = 'E';
    int currentNr = 2;
    int moveTiles = 1;
    int moveAmount = 2;

    while (currentNr < n*n)
    {
        if (currentNr+moveTiles > n*n)
            moveAmount = 1;

        for (int i = 0; i < moveAmount ; i++)
        {
            for (int j = 0; j < moveTiles; j++)
            {
                if (dir == 'E')
                    currentJ++;
                else if (dir == 'N')
                    currentI--;
                else if (dir == 'W')
                    currentJ--;
                else if (dir == 'S')
                    currentI++;
                A[currentI * n + currentJ] = currentNr;
                currentNr++;
            }
            if (dir == 'E')
                dir = 'N';
            else if(dir == 'N')
                dir = 'W';
            else if (dir == 'W')
                dir = 'S';
            else if (dir == 'S')
                dir = 'E';
        }
        moveTiles++;
    }
}

int main ()
{
    int m;
    cout << "Ivesti sk.: ";
    cin >> m;
    n = sqrt(m);
    int A[m];

    alg(A);
    disp(A);

    return 0;
}
