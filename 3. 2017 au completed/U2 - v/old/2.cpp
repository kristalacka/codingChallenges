#include <iostream>
#include <locale>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string sal(string kal, int n)
{
    for (int i = n; i<kal.length()-1; i++)
    {
        kal[i] = kal[i+1];
    }
    kal = kal.substr(0, kal.length()-1);
    cout << kal << '\n';
    return kal;
}

string check(string kal)
{
    vector<int> toRemove;
    for (int i = 0; i<kal.length(); i++)
    {
        //cout << kal[i];
        if(kal[i] == kal[i+1] && i!= kal.length())
            toRemove.push_back(i);
        else if (kal[i-1] == kal[i] && i!= 0)
            toRemove.push_back(i);
    }
    for (int i = 0; i<toRemove.size(); i++)
    {
        kal = sal(kal, toRemove[i]);
        //cout << toRemove[i] << ' ';
    }
    //cout << kal << '\n';

    return kal;
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
        A[i] = check(A[i]);
    }


    return 0;
}
