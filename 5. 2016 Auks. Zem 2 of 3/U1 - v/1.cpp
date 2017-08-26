//https://cboard.cprogramming.com/cplusplus-programming/154841-problem-stringstream-convert.html
#include <iostream>
#include <locale>
#include <fstream>
#include <sstream>

using namespace std;

const string Spalvos[10] = {"juoda", "ruda", "raudona", "oranzine", "geltona", "zalia", "melyna", "violetine", "pilka", "balta"};
const string pakSpalvos[3] = {"auksine", "sidabrine", "bespalve"};

struct schema
{
    double om; //omai
    string strOm;
    string pak; //paklaida (%)
    int p; //laipsnis
    string rez;
};

void ziedai(schema a)
{
    a.rez = "";
    int dig = a.om;
    while (dig>=10)
        dig/=10;

    a.rez += Spalvos[dig];

    dig = a.om;

    if (a.strOm.length()>=2)
    {
        while (dig>=100)
            dig/=10;
        dig %=10;
    }
    else
        dig = 0;
    a.rez += ' ' + Spalvos[dig];

    dig = a.p;
    a.rez += ' ' + Spalvos[dig] + ' ';

    if (a.pak == "5")
        a.rez += pakSpalvos[0];
    else if (a.pak == "10")
        a.rez += pakSpalvos[1];
    else if (a.pak == "20")
        a.rez += pakSpalvos[2];

    cout << a.rez << '\n';
}
int main()
{
    int n;
    string a;
    ifstream in ("U1.txt");
    in>>n;
    schema A[n];
    for (int i = 0; i<n; i++)
    {
        in>>a;
        for (int j = 1; j < a.length(); j++)
            if (a[j] == '+')
            {
                if (a[j-1] == 'k' || a[j-1] == 'M' || a[j-1] == 'G')
                    A[i].strOm = a.substr(0, j-1);
                else
                    A[i].strOm = a.substr(0, j); //varza

                stringstream convert(A[i].strOm);
                convert>>A[i].om; //varza keiciama i numeri
                convert.clear();

                switch(a[j-1])
                {
                    case 'k':
                        A[i].om *= 1000;
                        break;
                    case 'M':
                        A[i].om *= 1000000;
                        break;
                    case 'G':
                        A[i].om *= 1000000000;
                }
                A[i].p = 0;
                int laips = A[i].om;
                while (laips%10 == 0)
                {
                    if (laips>=100)
                    {
                        A[i].p++;
                        laips = laips/10; //nustatomas laipsnis
                    }
                    else
                        break;
                }
                A[i].pak = a.substr(j+1, a.length());
                ziedai(A[i]);
                break;
            }
    }
    in.close();
    return 0;
}
