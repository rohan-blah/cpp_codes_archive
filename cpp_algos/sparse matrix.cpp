// The Method For Saving a Sparse Matrix ...
#include <iostream>
using namespace std;
int main()
{
    int sparse_Matrix[4][5]
    {
        {0, 3, 0, 4, 0 },{0, 2, 0, 0, 1 },{2, 5, 1, 0, 0 },{0, 2, 0, 0, 3 }
    };

    int nze= 0;
    int i, j;
    //Display the matrix first for user to understand ...
    cout<<"The Sparse Matrix is:\n";
    for(i=0;i<4;i++)
    {

        for(j=0;j<5;j++)
        {
            cout<<sparse_Matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    //Finding Number of Non-Zero-Elements in the Sparse ...
    for(i=0; i<4; i++)
    {
        for(j=0; j<5; j++)
        {
            if(sparse_Matrix[i][j] != 0)
            {
                nze++;
            }
        }
    }
    int k = 0;
    // Now Compressing the Sparse Matrix ...
    int compMatrix[3][nze];
    for(i=0; i<4; i++)
    {
        for(j=0; j<5; j++)
        {
            if(sparse_Matrix[i][j] != 0)
            {
                compMatrix[0][k] = i;
                compMatrix[1][k] = j;
                compMatrix[2][k] = sparse_Matrix[i][j];
                k++;
            }
        }
    }

    cout << "Displaying Above Sparse Matrix in compact Form." << endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<nze; j++)
            cout << compMatrix[i][j] << " ";
        cout << endl;
    }

}
