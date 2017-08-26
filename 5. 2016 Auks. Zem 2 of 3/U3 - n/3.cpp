#include <iostream>
#include <locale>
#include <fstream>

using namespace std;

struct node
{
    bool state;
    node* neighbors[4];
    bool checked;
    int nr;
};

void rez(node A[][30], int n, int m)
{
    node defNode;
    defNode.state = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
                A[i][j].neighbors[0] = &defNode;
            else
                A[i][j].neighbors[0] = &A[i-1][j];
            if (i == n)
                A[i][j].neighbors[1] = &defNode;
            else
                A[i][j].neighbors[1] = &A[i+1][j];
            if (j==0)
                A[i][j].neighbors[2] = &A[i][m-1];
            else
                A[i][j].neighbors[2] = &A[i][j-1];
            if (j==m)
                A[i][j].neighbors[3] = &A[i][0];
            else
                A[i][j].neighbors[3] = &A[i][j+1];
        }

    node currentNode, prevNode;
    bool done = false;
    int nr = 0;


    cout << nr;

}

int main()
{
    int n, m;
    ifstream in ("U3.txt");
    node A[30][30];
    in>>n>>m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            in >> A[i][j].state;
            A[i][j].nr = i*m+j;
        }




    rez (A, n, m);
    in.close();
    return 0;
}
