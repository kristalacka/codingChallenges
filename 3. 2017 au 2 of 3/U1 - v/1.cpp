#include <iostream>
#include <locale>
#include <fstream>
#include <algorithm>

using namespace std;

string rev(string num, int i, int n)
{
    for (i; i<n; i++)
    {
        char temp = num[i];
        num[i] = num[(n-1) - i];
        num[(n-1) - i] = temp;
    }
    return num;
}

void lex(string num, string orig)
{
    bool done = false;
    bool res;
    while (!done)
    {
        res = true;
        for (int i =0; i<num.length(); i++)
            if (num[i] == orig[i])
                res = false;

        if (res)
        {
            cout << num << '\n';
            break;
        }
        int didzI = -1;
        for (int i=0; i<num.length()-1; i++)
            if (int(num[i]) < int(num[i+1]))
                didzI = i;

        if (didzI == -1)
        {
            done = true;
            break;
        }
        int didzJ = -1;
        for (int j=0; j<num.length(); j++)
            if (num[didzI]<num[j])
                didzJ = j;

        swap(num[didzI], num[didzJ]);

        string a = num.substr(0, didzI+1);
        string temp = num.substr(didzI+1, num.length());
        reverse(temp.begin(), temp.end());
        num = a+temp;
    }
    if (!res)
        cout << "NEGALIMA\n";
}

string rik(string num)
{
    int k, l;
    for (int i=0; i<num.length()-1; i++)
    {
        k = i;
        for (int j= i+1; j<num.length(); j++)
            if (int(num[j]) < int(num[k]))
                k = j;
        l = num[k];
        num[k] = num[i];
        num[i] = l;
    }
    return num;
}

int main ()
{
    int n;
    string Nr[20];
    ifstream in("U1.txt");
    in>>n;
    for (int i=0; i<n; i++)
    {
        in>>Nr[i];
        string orig = Nr[i];
        Nr[i] = rik(Nr[i]);
        lex(Nr[i], orig);
    }
    in.close();

    return 0;
}
