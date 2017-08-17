#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

void skait(int &n, bool A[][5]);
void skaic(int n, bool A[][5], int KoordX[], int KoordY[], int viso);
bool tinkamas(int i, int j, int NetX[], int NetY[], int net);

int main ()
{
    bool A[5][5];
    int n, KoordX[100], KoordY[100], viso=0;
    skait(n, A);
    skaic(n, A, KoordX, KoordY, viso);
    return 0;
}

void skait(int &n, bool A[][5])
{
    ifstream in ("U3.txt");
    in>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            in>>A[i][j];
    in.close();
}

void skaic(int n, bool A[][5], int KoordX[], int KoordY[], int viso)
{
    int X[4], Y[4]; //kampu koordinates
    int a=0, NetX[10], NetY[10], net=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (A[i][j]==1) //jei langelis tinka
            {
                if (a==0 || a==1) //primu dveju kampu kooridnates nuskaitomos
                {
                    X[a]=i;
                    Y[a]=j;
                    a++;
                }
                if (a==2 && tinkamas(i, j, NetX, NetY, net)) //trecias kampas
                {
                    X[a]=i;
                    Y[a]=j;
                    a++;
                    for (int k=i; k<n; k++)
                        for (int l=j; l<n; l++)
                        {
                            if (k-Y[2]==Y[1]-Y[0] && l-X[2]==X[1]-X[0])
                            {
                                X[3]=l;
                                Y[3]=k;
                                a++;
                            }
                        }
                }
            }
            if (a!=4)
            {
                NetX[net]=X[2];
                NetY[net]=Y[2];
                net++;
            }
            else if (a==4)
            {
                for (int k=0; k<4; k++)
                {
                    cout << '(' << X[k] << "; " << Y[k] << ") ir ";
                    KoordX[k+viso*4]=X[k];
                    KoordY[k+viso*4]=Y[k];
                }
                cout << '\n';
                viso++;
            }
            i=0;
            j=0;
            a=0;
        }
    }
    cout << "\nviso: " << '\n';
}

bool tinkamas(int i, int j, int NetX[], int NetY[], int net)
{
    bool ats=true;
    for (int k=0; k<net; k++)
    {
        if (j==NetX[k] && i==NetY[k])
            ats=false;
    }
    return ats;
}
