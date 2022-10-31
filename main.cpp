#include <iostream>
#include <cstdlib>
#include "classes_and_arrays.h"

using namespace std;

int main()
{
    int det;
    int i=0, j=0;
    Matrix<3> mat1;
    Matrix<3> mat2;
    Matrix<3> sum;
    Matrix<3> diff;
    Matrix<3> multip;

    mat1.set_data(0, 0, 2);

    for (i = 0; i<sum.SIZE; i++){
        for (j = 0; j<sum.SIZE; j++){
            sum.set_data(i, j, add_mats(mat1, mat2).get_data(i, j));
            cout << sum.get_data(i, j) << " ";
            if (j == sum.SIZE-1)
                cout << endl;
        }
    }

    for (i = 0; i<diff.SIZE; i++){
        for (j = 0; j<diff.SIZE; j++){
            diff.set_data(i, j, sub_mats(mat1, mat2).get_data(i, j));
            cout << diff.get_data(i, j) << " ";
            if (j == diff.SIZE-1)
                cout << endl;
        }
    }

    for (i = 0; i<multip.SIZE; i++){
        for (j = 0; j<multip.SIZE; j++){
            multip.set_data(i, j, multip_mats(mat1, mat2).get_data(i, j));
            cout << multip.get_data(i, j) << " ";
            if (j == multip.SIZE-1)
                cout << endl;
        }
    }

    det = determinant(mat1, 3);
    cout << "determinant " << det << endl;

    return 0;
}
