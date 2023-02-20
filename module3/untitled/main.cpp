#include <iostream>
#include <iomanip>
using namespace std;
void output_matr(int a[][3], int n, int m)
{int i, j;
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
            cout << setfill(' ') <<left<< setw(5) << a[i][j] ;
        cout << endl;
    }
}
int main()
{int x = 10;
    int y = 4;
    double d = static_cast<double>(x) / y;
    cout << d;}