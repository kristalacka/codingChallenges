#include <iostream>
#include <locale>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

struct skaiciai
{
    string r;
    int nr;
};

void convN(skaiciai a)
{
    map<int, string> sk;
    sk[1] = "I";
    sk[4] = "IV";
    sk[5] = "V";
    sk[9] = "IX";
    sk[10] = "X";
    sk[40] = "XL";
    sk[50] = "L";
    sk[90] = "XC";
    sk[100] = "C";
    sk[400] = "CD";
    sk[500] = "D";
    sk[900] = "CM";
    sk[1000] = "M";
    int copija = a.nr;
    a.r = "";
    while (copija>0)
    {
        for (auto it = sk.rbegin(); it!=sk.rend(); it++)
        {
            if (copija >= it->first)
            {
                a.r += it->second;
                copija-=it->first;
                break;
            }
        }
    }
    cout << a.nr << ' ' << a.r << '\n';
}

void convR(skaiciai a)
{
    map<char, int> sk;
    sk['I'] = 1;
    sk['V'] = 5;
    sk['X'] = 10;
    sk['L'] = 50;
    sk['C'] = 100;
    sk['D'] = 500;
    sk['M'] = 1000;

    int i = 0, n = 0;
    a.nr = 0;
    while(i<a.r.length())
    {
        if (sk[a.r[i]]>=sk[a.r[i+1]] && sk[a.r[i+1]] >= sk[a.r[i+2]])
        {
            a.nr+=sk[a.r[i]]+sk[a.r[i+1]];
            i++;
        }
        else if (sk[a.r[i]]>=sk[a.r[i+1]] && sk[a.r[i+1]] < sk[a.r[i+2]])
            a.nr+=sk[a.r[i]];
        else
        {
            a.nr += sk[a.r[i+1]]-sk[a.r[i]];
            i++;
        }
        i++;
    }
    cout << a.r << ' ' << a.nr <<'\n';
}
int main()
{
    int n, m;
    ifstream in ("U2.txt");
    in>>n;
    skaiciai R[n];
    for (int i = 0; i<n; i++)
    {
        in>>R[i].r;
        convR(R[i]);
    }

    in>>m;
    skaiciai N[m];
    for (int i = 0; i<m; i++)
    {
        in>>N[i].nr;
        convN(N[i]);
    }
    in.close();
    return 0;
}
