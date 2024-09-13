#include "Matrix.h"

int main() {
    cout << "Welcome to My 2-D Vector Processor!\n";

    // Create input file stream & open the file
    ifstream inFile("dataValid.txt");

    // Verify the input file is good - if not exit
    if (!inFile) {
        cout << "Error opening input file!\n";
        return -1;
    }

    string inputStr1, inputStr2;
    vector<vector<int>> v1, v2;
    int rows1, cols1, rows2, cols2;
    bool valid1 = false, valid2 = false;

    while (getline(inFile, inputStr1)) {
        if (getline(inFile, inputStr2)) {
            cout << "\n\nPROCESSING A SET OF MATRICES\n";

            cout << "\n\tPROCESSING FIRST MATRIX\n";
            // Verify vector, if valid, printVector & processVector
            valid1 = verifyVector(inputStr1, v1, rows1, cols1);
            if (valid1) {
                printVector(v1);
                processVector(v1);
            }
            else {
                cout << "First matrix is invalid.\n";
            }

            cout << "\n\tPROCESSING SECOND MATRIX\n";
            // Verify vector, if valid, printVector & processVector
            valid2 = verifyVector(inputStr2, v2, rows2, cols2);
            if (valid2) {
                printVector(v2);
                processVector(v2);
            }
            else {
                cout << "Second matrix is invalid.\n";
            }

            cout << "\n\tPROCESSING BOTH MATRICES\n";
            // If both vectors are valid, check dimensions and perform operations
            if (valid1 && valid2) {
                if (rows1 == rows2 && cols1 == cols2) {
                    cout << "\n\tAdding Matrices:\n";
                    addTwoMatrices(v1, v2);
                }
                else {
                    cout << "Matrices cannot be added due to size mismatch.\n";
                }

                if (cols1 == rows2) {
                    cout << "\n\tMultiplying Matrices:\n";
                    multiplyTwoMatrices(v1, v2);
                }
                else {
                    cout << "Matrices cannot be multiplied due to size mismatch.\n";
                }
            }

        }
        else {
            cout << "Error reading second matrix from the file.\n";
        }
    }

    inFile.close();
    return 0;
}
