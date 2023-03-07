#include<iostream>
#include<vector>
#define SIZE_M 2
#define SIZE_N 3
#define SIZE_S 4

using namespace std;

int main()
{
    //r = a * b + c
    int matrix_a[SIZE_M][SIZE_N] = {{1,2,3},{1,2,3}};
    int matrix_b[SIZE_N][SIZE_S] = {{3,3,3,3},{3,3,3,3},{3,3,3,3}};
    int matrix_c[SIZE_M][SIZE_S] = {{4,4,4,4},{4,4,4,4}};
    int matrix_r[SIZE_M][SIZE_S];
    int matrix_t[SIZE_M][SIZE_S];

    int count = 0;
    
    for(int m = 0; m < SIZE_M; m++)
    {
        for(int s = 0; s < SIZE_S; s++)
        {
            matrix_r[m][s] = 0;
            matrix_t[m][s] = 0;
            for(int n = 0; n < SIZE_N; n++)
            {
                matrix_t[m][s] = matrix_a[m][n] * matrix_b[n][s];
                count++;
                matrix_r[m][s] += matrix_t[m][s];
                count++;
            }
        }
    }
     int count_add = 0;
    for(int m = 0; m < SIZE_M; m++)
    {
        for(int s = 0; s < SIZE_S; s++)
        {
            matrix_r[m][s] = matrix_r[m][s] + matrix_c[m][s];
            count_add++;
        }
    }
    
    for(int m = 0; m < SIZE_M; m++)
    {
        for(int s = 0; s < SIZE_S; s++)
        {
            cout<<matrix_r[m][s]<<"\t";
        }
        cout<<endl;
    }
    cout<<"count:"<<count<<endl;
    cout<<"count_add: "<<count_add<<endl;

    return 0;
}