#include <iostream>
#include <locale>
#include <fstream>
#include <iomanip>

using namespace std;

struct mikro
{
    int nr, t, K[4];
};

void skait(int &n, mikro A[]);
void rez(int n, mikro A[]);
void sritis(int &n, mikro A[], int &zon, double &vidr);
void sal(int a, int &n, mikro A[]);
double vid(int n, mikro A[]);

int main ()
{
    mikro A[1000];
    int n;
    skait(n, A);
    rez(n, A);
    return 0;
}

void skait(int &n, mikro A[])
{
    ifstream in ("U2.txt");
    in>>n;
    for (int i=0; i<n; i++)
    {
        in>>A[i].nr>>A[i].t;
        for (int j=0; j<4; j++)
            in>>A[i].K[j];
    }
    in.close();
}

void rez(int n, mikro A[])
{
    int zon;
    double vidr;
    sritis(n, A, zon, vidr);
    cout << zon << ' ' << n << ' ' << fixed << setprecision(0) << vidr << '\n'; //spauzdinami rezultatai
}

void sritis(int &n, mikro A[], int &zon, double &vidr)
{
    int a=n;
    for (int i=0; i<a; i++)
    {
        if (A[i].t<40)
        {
            sal(i, n, A); //pasalinamos netinkamos sritys
            i--;
        }
    }

    vidr=vid(n, A);
    a=n;
    zon=n;

    for (int i=0; i<n; i++) //ciklas per visas tinkamas zonas
    {
        for (int j=0; j<4; j++) //ciklas per kaimyninius zoidus
        {
            for (int o=0; o<n; o++) //ciklas per visas tinkamas zonas
            {
                if (A[o].nr==A[i].K[j]) //jei kamyninis zoidas lygus vinam is tinkamu zonu, ta zona yra pasalinama is pagrindinio saraso ir zonu skaicius sumazinamas vienetu
                {
                    sal(i, n, A);
                    zon--;
                }
            }
        }
    }
    n=a;
}

void sal(int a, int &n, mikro A[])
{
    for (int i=a; i<n-1; i++)
        A[i]=A[i+1];
    n--; //salinami strukturos masyvo elementai
}

double vid(int n, mikro A[]) //vidurkio apskaiciavimas
{
    double sum=0;
    for (int i=0; i<n; i++)
        sum+=A[i].t;

    return sum/n;
}
