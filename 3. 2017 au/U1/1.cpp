#include <iostream>
#include <locale>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

string stat(string nr);
void sal(string &z, int a);

int main ()
{
    int n;
    string Nr[20];
    ifstream in("U1.txt");
    in>>n;
    for (int i=0; i<n; i++)
    {
        in>>Nr[i];
        cout << stat(Nr[i]);
    }
    in.close();

    return 0;
}

string stat(string nr)
{
    string rez, kop=nr;
    int i=0, j=0;
    while(i<nr.length())
    {
        while(j<kop.length())
        {
            if (kop[j]!=nr[i])
            {
                sal(kop, j);
                rez[i]=kop[j];
            }
            else
                j++;
        }
        i++
    }
    if (rez.length()!=nr.length())
        return "NEGALIMA";
    return rez;
}

void sal(string &z, int a)
{
    for (int i=a; i<z.length()-1; i++)
        z[i]=z[i+1];
    z=z.substr(0, z.length()-1);
}
