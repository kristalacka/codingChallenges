#include <iostream>
#include <locale>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct elektrine
{
    int r, //atsargos
        p, //pagamina W per diena
        currentW, //dabar turima energija
        amntUsed; //kiek isnaudojo
};

struct fabrikas
{
    int w, //W kuriu reikia kasdien
        nA, //elektrine A
        nB; //elektrine B
};

void skaic(int n, int m, elektrine A[], fabrikas B[], int &days)
{
    bool cont = true; //jei reikia testi
    while(cont)
    {
        for (int i = 0; i < n; i++) //ciklas per elektrines, nustatomi ju dienos parametrai
        {
            if (A[i].r>=A[i].p)
                A[i].currentW = A[i].p;
            else
                A[i].currentW = A[i].r;
            A[i].amntUsed = 0;
        }

        for (int i = 0; i < m; i++) //ciklas per kiekviena fabrika
        {
            if (A[B[i].nA-1].currentW >= B[i].w) //jei pigesne elektrine turi W
            {
                A[B[i].nA-1].currentW-=B[i].w; //isimti is elektrines W
                A[B[i].nA-1].amntUsed+=B[i].w;
            }
            else if (A[B[i].nB-1].currentW >= B[i].w) //jei brangesne elektrine turi W
            {
                A[B[i].nB-1].currentW-=B[i].w; //isimti is elektrines W
                A[B[i].nB-1].amntUsed+=B[i].w;
            }
            else //jei nei viena elektrine negali teikti daugiau energijos
                cont = false; //ciklas nutraukiamas
        }

        for (int i = 0; i < n; i++)
            A[i].r-=A[i].amntUsed;

        if(cont)
        {
            days++;
            for (int i = 0; i < n; i++)
                cout << A[i].r << ' ';
            cout << '\n';
        }

    }
}

int main()
{
    int n, m;
    ifstream in ("U2.txt");
    in>> n >> m;
    elektrine A[n];
    fabrikas B[m];
    for (int i = 0 ; i < n; i++)
        in >> A[i].r >> A[i].p;


    int a, b;
    for (int i = 0; i < m ; i++)
    {
        in >> B[i].w >> a >> b;
        if (b<a)
        {
            B[i].nA = b;
            B[i].nB = a;
        }
        else
        {
            B[i].nA = a;
            B[i].nB = b;
        } //elektrines surusiuojamos pagal elektros kaina
    }

    in.close();

    int days = 0;
    skaic(n, m, A, B, days);
    cout << days;

    return 0;
}
