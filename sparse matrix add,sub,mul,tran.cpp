#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

struct MatrixElement {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int numRows, numCols, numElements;
    MatrixElement elements[MAX_SIZE];

public:
    SparseMatrix(int rows, int cols) {
        numRows = rows;
        numCols = cols;
        numElements = 0;
    }

    // Function to insert a non-zero element into the sparse matrix
    void insertElement(int row, int col, int value) {
        if (numElements < MAX_SIZE) {
            elements[numElements].row = row;
            elements[numElements].col = col;
            elements[numElements].value = value;
            numElements++;
        } else {
            cout << "Sparse matrix is full. Cannot insert more elements." << endl;
        }
    }

    // Function to compute the transpose of the sparse matrix
    SparseMatrix transpose() {
        SparseMatrix transposedMatrix(numCols, numRows);
        for (int i = 0; i < numElements; i++) {
            transposedMatrix.insertElement(elements[i].col, elements[i].row, elements[i].value);
        }
        return transposedMatrix;
    }

    // Function to add two sparse matrices
    SparseMatrix add(const SparseMatrix& otherMatrix) {
        if (numRows != otherMatrix.numRows || numCols != otherMatrix.numCols) {
            cout << "Matrix dimensions do not match. Cannot add." << endl;
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(numRows, numCols);

        int i = 0, j = 0;

        while (i < numElements && j < otherMatrix.numElements) {
            int row1 = elements[i].row;
            int col1 = elements[i].col;
            int row2 = otherMatrix.elements[j].row;
            int col2 = otherMatrix.elements[j].col;

            if (row1 == row2 && col1 == col2) {
                result.insertElement(row1, col1, elements[i].value + otherMatrix.elements[j].value);
                i++;
                j++;
            } else if (row1 < row2 || (row1 == row2 && col1 < col2)) {
                result.insertElement(row1, col1, elements[i].value);
                i++;
            } else {
                result.insertElement(row2, col2, otherMatrix.elements[j].value);
                j++;
            }
        }

        while (i < numElements) {
            result.insertElement(elements[i].row, elements[i].col, elements[i].value);
            i++;
        }

        while (j < otherMatrix.numElements) {
            result.insertElement(otherMatrix.elements[j].row, otherMatrix.elements[j].col, otherMatrix.elements[j].value);
            j++;
        }

        return result;
    }

    // Function to multiply two sparse matrices
    SparseMatrix multiply(const SparseMatrix& otherMatrix) {
        if (numCols != otherMatrix.numRows) {
            cout << "Matrix dimensions do not allow multiplication." << endl;
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(numRows, otherMatrix.numCols);

        for (int i = 0; i < numElements; i++) {
            int row1 = elements[i].row;
            int col1 = elements[i].col;
            int value1 = elements[i].value;

            for (int j = 0; j < otherMatrix.numElements; j++) {
                int row2 = otherMatrix.elements[j].row;
                int col2 = otherMatrix.elements[j].col;
                int value2 = otherMatrix.elements[j].value;

                if (col1 == row2) {
                    result.insertElement(row1, col2, result.elements[result.numElements - 1].value + (value1 * value2));
                }
            }
        }

        return result;
    }

    // Function to display the sparse matrix
    void display() {
        cout << "Sparse Matrix:" << endl;
        for (int i = 0; i < numElements; i++) {
            cout << elements[i].row << " " << elements[i].col << " " << elements[i].value << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for the sparse matrix: ";
    cin >> rows >> cols;

    SparseMatrix matrix1(rows, cols);
    SparseMatrix matrix2(rows, cols);

    cout << "Enter elements for the first matrix (row col value):" << endl;
    int numElements1;
    cin >> numElements1;
    cout << "Enter elements for the second matrix (row col value):" << endl;
    int numElements2;
    cin >> numElements2;

    cout << "Enter elements for the first matrix:" << endl;
    for (int i = 0; i < numElements1; i++) {
        int row, col, value;
        cin >> row >> col >> value;
        matrix1.insertElement(row, col, value);
    }

    cout << "Enter elements for the second matrix:" << endl;
    for (int i = 0; i < numElements2; i++) {
        int row, col, value;
        cin >> row >> col >> value;
        matrix2.insertElement(row, col, value);
    }

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    SparseMatrix transposeMatrix1 = matrix1.transpose();
    SparseMatrix transposeMatrix2 = matrix2.transpose();

    cout << "Transpose of Matrix 1:" << endl;
    transposeMatrix1.display();

    cout << "Transpose of Matrix 2:" << endl;
    transposeMatrix2.display();

    SparseMatrix sumMatrix = matrix1.add(matrix2);
    cout << "Sum of Matrix 1 and Matrix 2:" << endl;
    sumMatrix.display();

    SparseMatrix productMatrix = matrix1.multiply(matrix2);
    cout << "Product of Matrix 1 and Matrix 2:" << endl;
    productMatrix.display();

    return 0;
}
