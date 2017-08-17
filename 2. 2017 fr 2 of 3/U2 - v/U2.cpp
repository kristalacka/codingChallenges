#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

string zodis;
void tikrinti(string &tik, bool &rez);
void sal(string &zod, int n);

int main ()
{
    int n;
    bool rez=true;
    string prad, Zod[50], tikrinamas;
    ifstream in ("U2.txt");
    in>>n>>zodis;
    for (int i=0; i<n; i++)
    {
        in>>Zod[i]; //nuskaitymas
        tikrinamas=Zod[i];
        tikrinti(Zod[i], rez);
        if (rez) //zodis tikrinamas
            cout << tikrinamas << ": tinkamas\n";
        else
            cout << tikrinamas << ": netinkamas; Truksta: " << Zod[i] << '\n'; //spauzdinami rezultatai
    }
    in.close();
    return 0;
}

void tikrinti(string &tik, bool &rez)
{
    string kopija = zodis; //padaroma pradinio zodzio kopija
    int i=0, j=0;
    while (i<tik.length()) //ciklas per tirkrinamojo zodzio raides
    {
        while (j<kopija.length()) //ciklas per pradinio zodzio raides
        {
            if (kopija[j]==tik[i]) //jei tikrinamojo zodzio raide yra pradiniame zodyje
            {
                sal(kopija, j); //raide salinama is pagrindinio zodzio kopijos
                sal(tik, i); //raide salinama is tikrinamojo zodzio
                j=0;
            }
            else
                j++;
        }
        i++;
    }
    if (tik.length()!=0) //jei tikrinamajame zodyje dar yra raidziu
        rez=false; //zodis netinka
}

void sal(string &zod, int n)
{
    for (int i=n; i<zod.length()-1; i++)
        zod[i]=zod[i+1];
    zod = zod.substr(0, zod.length()-1);
}
