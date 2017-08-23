#include <iostream>
#include <locale>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct kamp
{
    int x, y;
};

struct ketr
{
    kamp K[4];
    string tipas;
    double s;
};

double dist(kamp a, kamp b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
string nTipas(kamp A[])
{
    if (abs(dist(A[1], A[2]) - dist(A[0], A[3])) < 0.001)
        return "Staciakampis";
    return "Lyiasone tr.";
}

double plot(ketr a)
{
    if (a.tipas == "Staciakampis")
        return dist(a.K[0], a.K[1])*dist(a.K[1], a.K[2]);

    double c = dist(a.K[0], a.K[1]);
    double b = dist(a.K[0], a.K[3]);
    double a1 = dist(a.K[1], a.K[2]);
    double h = sqrt(c*c-0.25*(b-a1)*(b-a1));
    return h*((a1+b)/2);
}
int main()
{
    int n;
    ifstream in ("U1.txt");
    in>>n;
    ketr A[n];

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<4; j++)
            in >> A[i].K[j].x >> A[i].K[j].y;

        A[i].tipas = nTipas(A[i].K);
        A[i].s = plot(A[i]);
        cout << i+1 << " - " << A[i].tipas << ' ' << fixed << setprecision(2) << A[i].s << '\n';
    }

    in.close();

    return 0;
}
