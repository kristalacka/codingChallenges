#include <iostream>
#include <locale>
#include <fstream>
#include <cmath>

using namespace std;

int n, viso = 0, a = 0;
double diff = 0.002;

struct full
{
    int x, y;

    double dist(full kitas)
    {
        return sqrt((kitas.x - x)*(kitas.x - x)+(kitas.y - y)*(kitas.y - y));
    }
};

struct kampai
{
    full kamp[4];
};

kampai kvad[20];

void test(full B[])
{
    for (int i=0; i<a; i++) //1 kampas
    {
        for (int j=i+1; j<a; j++) //2 kampas
        {
            double edgeDist1 = B[i].dist(B[j]); // atstumas tarp 1 ir 2 kampu
            for (int o = j+1; o<a; o++) // ieskomas 3 kampas
            {
                double edgeDist2 = B[i].dist(B[o]); //atstumas tarp 1 ir 3 kampu
                if (edgeDist1 == edgeDist2) //jei atstumas iki 2 ir 3 kampu sutampa
                {
                    for (int k = o; k < a; k++) // ieskomas 4 kampas
                    {
                        if (abs(B[i].dist(B[k])-B[j].dist(B[o]))<diff && abs(B[o].dist(B[k])-B[j].dist(B[k]))<diff && abs(B[o].dist(B[k])-edgeDist1)<diff)
                            //jei atstumas tarp istrizainiu sutampa, atstumas nuo 4 iki 2 ir 3 sutampa, ir atstumas nuo 4 iki gretimu kampu sutampa su 1 kampo gretimau kampu atstumo
                        {
                            kvad[viso].kamp[0] = B[i];
                            kvad[viso].kamp[1] = B[j];
                            kvad[viso].kamp[2] = B[k];
                            kvad[viso].kamp[3] = B[o];
                            viso++;
                        }
                    }
                }
            }
        }
    }

}

int main ()
{
    ifstream in ("U3_2.txt");
    in>>n;
    bool A[n*n];
    full B[n*n];
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            in>>A[i * n + j];
            if (A[i * n + j]) //jei pilnaviduris
            {
                B[a].x = i;
                B[a].y = j;
                a++;
            }
        }

    }
    in.close();
    //cout << a;
    test(B);

    cout << viso << '\n';
    for (int i = 0; i < viso; i++)
    {
        for (int j=0; j < 4; j++)
        {
            cout << '(' << kvad[i].kamp[j].x+1 << ',' << kvad[i].kamp[j].y+1 << ')';
            if (j!=3)
                cout << " ir ";
        }
        cout << '\n';
    }
    return 0;
}



