#include "Matrix.h"

// Checks if a string contains only digits
bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

// Checks if a string contains only binary digits (0 and 1)
bool isBinary(string str) {
    return str.find_first_not_of("01") == string::npos;
}

// Validates and loads matrix data from a string into a vector
bool verifyVector(string record, vector<vector<int>>& vec, int& row, int& col) {
    stringstream ss(record);

    // Read number of rows and columns
    if (!(ss >> row >> col)) {
        return false; // Invalid format for rows and columns
    }

    // Temporary vector to hold the matrix data
    vector<vector<int>> tempVec(row, vector<int>(col));

    // Read the matrix elements
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int val;
            if (!(ss >> val) || (val != 0 && val != 1)) {
                return false; // Invalid value (non-binary or missing data)
            }
            tempVec[i][j] = val; // Store valid data in the temp vector
        }
    }

    // If all data is valid, assign it to the output vector and return true
    vec = tempVec;
    return true;
}

// Prints the vector in a formatted manner
void printVector(vector<vector<int>> vec) {
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            cout << setw(3) << elem; // Adjust width for neat printing
        }
        cout << endl;
    }
}

// Processes the vector to check for reflexivity and symmetry
void processVector(vector<vector<int>> vec) {
    int size = vec.size();
    bool reflexive = true;
    bool symmetric = true;

    // Check if matrix is square
    if (size != vec[0].size()) {
        cout << "Matrix is not square and cannot be evaluated for reflexivity or symmetry.\n";
        return;
    }

    // Check for reflexivity
    for (int i = 0; i < size; ++i) {
        if (vec[i][i] != 1) {
            reflexive = false;
            break;
        }
    }

    // Check for symmetry
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (vec[i][j] != vec[j][i]) {
                symmetric = false;
                break;
            }
        }
    }

    // Print results
    cout << "Matrix is " << (reflexive ? "reflexive" : "not reflexive") << ".\n";
    cout << "Matrix is " << (symmetric ? "symmetric" : "not symmetric") << ".\n";
}

// Adds two matrices and prints the result
void addTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2) {
    int rows1 = vec1.size(), cols1 = vec1[0].size();
    int rows2 = vec2.size(), cols2 = vec2[0].size();

    // Check if matrices have the same dimensions
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrices cannot be added due to size mismatch.\n";
        return;
    }

    vector<vector<int>> result(rows1, vector<int>(cols1));

    // Perform element-wise addition
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            result[i][j] = vec1[i][j] + vec2[i][j];
        }
    }

    cout << "Result of matrix addition:\n";
    printVector(result);
}

// Multiplies two matrices and prints the result
void multiplyTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2) {
    int rows1 = vec1.size(), cols1 = vec1[0].size();
    int rows2 = vec2.size(), cols2 = vec2[0].size();

    // Check if matrices can be multiplied
    if (cols1 != rows2) {
        cout << "Matrices cannot be multiplied due to size mismatch.\n";
        return;
    }

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += vec1[i][k] * vec2[k][j];
            }
        }
    }

    cout << "Result of matrix multiplication:\n";
    printVector(result);
}
