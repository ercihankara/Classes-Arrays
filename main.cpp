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

    Matrix<3> sum = add_mats(mat1, mat2);
    Matrix<3> diff = sub_mats(mat1, mat2);
    Matrix<3> multip = multip_mats(mat1, mat2);

    print_matrix(sum);
    cout << endl;
    print_matrix(diff);
    cout << endl;
    print_matrix(multip);
    cout << endl;

    det = determinant(mat1, 3);
    cout << "determinant " << det << endl;

    return 0;
}
