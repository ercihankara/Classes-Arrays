// Ercihan Kara - 2375160
#include <iostream>
#include <cstdlib>
#include "classes_and_arrays.h"

using namespace std;

template <int N>
void print_matrix(Matrix<N> mat){
    for (int i = 0; i<mat.SIZE; i++){
        for (int j = 0; j<mat.SIZE; j++){
            cout << mat.get_data(i, j) << " ";
            if (j == mat.SIZE-1)
                cout << endl;
        }
    }
}

int main()
{
    int det;
    int i=0, j=0;
    Matrix<3> mat1;
    Matrix<3> mat2;

    mat1.set_data(0, 0, 2);

    cout << "Matrix 1: " << endl;
    print_matrix(mat1);

    cout << "Matrix 2: " << endl;
    print_matrix(mat2);

    Matrix<3> sum = add_mats(mat1, mat2);
    Matrix<3> diff = sub_mats(mat1, mat2);
    Matrix<3> multip = multip_mats(mat1, mat2);

    cout << "Sum matrix: " << endl;
    print_matrix(sum);
    cout << "Difference matrix: " << endl;
    print_matrix(diff);
    cout << "Multiplication matrix: " << endl;
    print_matrix(multip);

    det = determinant(mat1, 3);
    cout << "Determinant of Matrix 1: " << det << endl;

    return 0;
}
