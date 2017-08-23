#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

bool notIn(int nr, int A[], int n)
{ //patikrina ar skaicius jau masyve
    for (int i = 0; i < n; i++)
        if (A[i] == nr)
            return false;

    return true;
}

bool hasRepeats(int A[], int n)
{ //tikrina ar skaicius pasikartoja masyve
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            if (A[j]==A[i] && i!=j)
                return true;

    return false;
}

int main()
{
    ifstream in ("U3.txt");
    int w, h;
    in>>w>>h;
    int A[h][w];
    int B[max(h, w)][max(h, w)];
    int C[min(h, w)];

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            in>>A[i][j];
            B[i][j] = A[i][j]; //nuskaitymas
        }

    bool valid = true; //lotyniskas kvadratas imanomas

    if (h>w) //jei reikia uzpildyti horizontalia eile
        for (int i = 0; i < h; i++)
        {
            if (hasRepeats(A[i], w)) //jei stulpelis turi pasikartojanciu skaiciu
            {
                valid = false; //lotyniskas kvadratas neimanomas
                break;
            }
            else for (int j = 0; j < h; j++)
                if (notIn(j+1, A[i], w)) //jei skaicius nera vienas is virs jo esanciu
                    B[i][h-1] = j+1; //skaicius irasomas
        }

    else if (w>h) //jei reikia uzpildyti vertikalia eile
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++) //sudaromas masyvas skaiciu, nuo kuriu priklauso rezultatas
                C[j] = B[j][i];

            if (hasRepeats(C, h)) //jei stulpelis turi pasikartojanciu skaiciu
            {
                valid = false; //lotyniskas kvadratas neimanomas
                break;
            }

            else for (int j = 0; j < w; j++)
                if (notIn(j+1, C, h)) //jei skaicius nera vienas is uz jo esanciu
                    B[w-1][i] = j+1; //skaicius irasomas
        }

    if(valid)
        for (int i = 0; i < max(h, w); i++)
        {
            for (int j = 0; j < max(h, w); j++)
                cout << B[i][j] << ' ';
            cout << '\n';
        }
    else
        cout << "Neimanoma\n";

    return 0;
}
