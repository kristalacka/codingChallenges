#include <iostream>
#include <locale>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string sal(string kal, int n)
{
    for (int i = n; i<kal.length()-1; i++)
        kal[i] = kal[i+1];
    kal = kal.substr(0, kal.length()-1);

    return kal;
}

void check(string &kal, int &maxIlg, char &sim)
{
    int i = 0;
    while (i<kal.length())
    {
        int a = i;
        vector<int> toRemove;
        while (kal[a] == kal[a+1])
        {
            toRemove.push_back(a);
            a++;
        }

        i++;
        if (kal[a] != kal[a+1] && toRemove.size()>0)
        {
            toRemove.push_back(a);

            if (toRemove.size()>maxIlg)
            {
                maxIlg = toRemove.size();
                sim = kal[toRemove[0]];
            }

            for (int j = toRemove.size()-1; j>=0; j--)
                kal = sal(kal, toRemove[j]);
            i = 0;
        }
    }
}

int main ()
{
    ifstream in ("U2.txt");
    int k,n;
    in>>k>>n;
    char C[n+1];
    string A[k];
    for (int i = 0; i < k; i++)
    {
        in.ignore(256, '\n');
        in.get(C, n+1);
        A[i] = C;
        int maxIlg = 0;
        char sim;
        check(A[i], maxIlg, sim);
        if (maxIlg > 0)
            cout << "Max ilgis = " << maxIlg << " simbolis " << sim << '\n';
        else
            cout << "Nebuvo metamos sekos\n";

        if (A[i].length() > 0)
            cout << A[i] << '\n';
        else
            cout << "Pertavarkyta eilute tuscia\n";
        cout << '\n';
    }

    return 0;
}
