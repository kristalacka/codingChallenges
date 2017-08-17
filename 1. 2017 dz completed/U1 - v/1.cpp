#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct skaiciai
{
    int sk;

    int len(int a)
    {
        int i=1;
        while (a>=10)
        {
            i++;
            a/=10;
        }
        return i; //randa skaiciaus skaitmenu kieki
    }

    int pirmsk(int a)
    {
        int sk, k=1;
        for (int i=1; i<len(a); i++)
            k*=10;
        sk=a/k;
        return sk; //randa pirma skaitmeni
    }

    int passk(int a)
    {
        int sk;
        sk=a%10;
        return sk; //randa paskutini skaitmeni
    }
};

void skait(int &n, skaiciai A[]);
void rez(int n, skaiciai A[]);
void skaic(int &n, skaiciai A[]);

int main()
{
    int n;
    skaiciai A[100];
    skait(n, A);
    rez(n, A);
    return 0;
}

void skait(int &n, skaiciai A[])
{
    ifstream in ("U1.txt");
    in>>n;
    for (int i=0; i<n; i++)
    {
        in>>A[i].sk;
    } //skaitomi duomenys
    in.close();
}

void skaic(int &n, skaiciai A[], int &dpradz, int &dpab)
{
    int ilg=0, pab=0, pradz=0, didz=0;
    for (int i=0; i<n-1; i++)
    {
        if (A[i].passk(A[i].sk)!=A[i+1].pirmsk(A[i+1].sk))
        {
            pab=i+1;
            ilg=pab-pradz;
            if (ilg>didz)
            {
                dpab=pab;
                dpradz=pradz;
                didz=ilg; //nustatomas didziausias sekos ilgis, tos sekos pradzia ir pabaiga
            }
            pradz=i+1;
        }
    }
}

int suma(skaiciai A[], int dpradz, int dpab)
{
    int sum=0, a;
    for (int i=dpradz; i<dpab; i++)
    {
        a=A[i].sk;
        for (int j=1; j<A[i].len(A[i].sk)+1; j++)
        {
            sum+=a%10;
            a/=10; //sumuojami skaitmenys
        }
    }
    return sum;
}

void rez(int n, skaiciai A[])
{
    int dpradz=0, dpab=0;
    skaic(n, A, dpradz, dpab);
    cout <<  "Sekos pradzia: " << dpradz+1 << '\n';
    cout << "Sekos ilgis: " << dpab-dpradz << '\n';
    cout << "Sekos skaitmenu suma: " << suma(A, dpradz, dpab) << '\n';
}
