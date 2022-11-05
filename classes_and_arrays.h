// helper functions are defined here!
#include <iostream>
#include <cstdlib>

using namespace std;

/* templates used for passing data type as a parameter so that
   there is no need to write the same code
   part for different data types */
template <int N>
class Matrix
{
    private:
        double data[N][N];
    public:
        int const SIZE = N;
        // the constructor for the class
        Matrix();
        // get the data at the position (row, column)
        int get_data(int row, int column) const;
        // set the data at the position (row, column)
        void set_data(int row, int column, int value);
};

// initialize the matrix as identity matrix
template <int N>
Matrix<N>::Matrix(){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++)
        {
            if (row == col)
                data[row][col] = 1;
            else
                continue;
        }
    }
}

// set an element for the desired indices
template <int N>
void Matrix<N>::set_data(int row, int column, int value){
    int checkher = 1;
    try{
        if(row < SIZE & column < SIZE)
            data[row][column] = value;
        else
            throw checkher;
    }
    catch (int checkher) {
        cout << "indices are not valid, check again \n";
    }
}

// get an element with the desired indices
template <int N>
int Matrix<N>::get_data(int row, int column) const{
    int checkher = 1;
    try{
        if(row < SIZE & column < SIZE)
            return data[row][column];
        else
            throw checkher;
    }
    catch (int checkher) {
        cout << "indices are not valid, check again \n";
    }
}

// add two matrices
template <int N>
Matrix<N> add_mats(Matrix<N> a1, Matrix<N> a2){
    int const size = a1.SIZE;
    int value;
    Matrix<N> sum;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            value = a1.get_data(i, j) + a2.get_data(i, j);
            sum.set_data(i, j, value);
        }
    }

    return sum;
}

// subtract two matrices from each other, absolute value is considered
template <int N>
Matrix<N> sub_mats(Matrix<N> a1, Matrix<N> a2){
    int const size = a1.SIZE;
    int value;
    Matrix<N> subt;
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            value = abs(a1.get_data(i, j) - a2.get_data(i, j));
            subt.set_data(i, j, value);
        }
    }

    return subt;
}

// multiply two matrices
template <int N>
Matrix<N> multip_mats(Matrix<N> a1, Matrix<N> a2){
    int const size = a1.SIZE;
    int multip;
    Matrix<N> mult; // square matrices

    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            for(int h = 0; h < size; h++){
                multip += a1.get_data(i, h)*a2.get_data(h, j);
                mult.set_data(i, j, multip);
            }
        }
    }

    return mult;
}

/* get cofactor of a matrix
   expanding along row 1 */
template<int N>
// row is the name of row, col is the column
void CoFactor(Matrix<N>& mat, Matrix<N>& holder, int row, int col)
{
    // local parameters for looping purposes
    int i = 0, j = 0;
    int size = mat.SIZE;
    // holder matrix to accumulate the cofactors of the input matrix

    for (int row_in = 0; row_in < size; row_in++)
    {
        for (int col_in = 0; col_in < size; col_in++)
        {
            /* loop through the elements of matrix
               that are not part of the corresponding row and column
               and copy them into the holder matrix */

            if (row_in != row && col_in != col)
            {
                holder.set_data(i, j++, mat.get_data(row_in, col_in));

                /* when the row is filled with the data that will be used
                   for determinant definition, pass to the next row */
                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* find the determinant of a matrix using cofactor expansion
   method in a recursive manner */
template<int N>
int determinant(Matrix<N> mat, int size)
{
    int det = 0;
    int sign = 1;
    // expanding along row 1, arrangable
    int row = 0;
    // int size = mat.SIZE;

    //  if matrix consists of single element, return the only value
    if (size == 1)
        return mat.get_data(0, 0);

    /* holder matrix to accumulate the cofactors of the input matrix,
       input to the CoFactor function */
    Matrix<N> holder;

    for (int col = 0; col < size; col++)
    {
        // get cofactor of matrix through the first row expansion
        CoFactor(mat, holder, row, col);
        // apply cofactor expansion formula recursively
        det += sign * mat.get_data(row, 0) * determinant(holder, size - 1);
        // change the sign parameter's sign at each spin
        sign = -sign;
    }

    return det;
}

/* For the functions that implement
   addition, subtraction and multiplication, calling by value method
   is used since no changes on the input matrices are realized,
   only getting the values of the matrix elements is enough for these functions */

/* However, for the determinant case, since we are following a recursive manner
   by using cofactor expansion, we need to update the Matrix objects that take place in
   the computation of cofactor process. Therefore, for the CoFactor function,
   call by reference method is used so that changes realized in the function can be felt
   by the determinant function for recursion purposes. */
