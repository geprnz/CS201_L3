#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// PRE: Accepts a string that is a record read from the input file which should contain
// numeric data separated by spaces. This data should contain:
// numberOfRows numberOfCols int int int int
// where ‘int’ values should be only 0s and 1s
// POST: Returns true if the vector is valid or false otherwise. Updates 'vec' with the
// valid values. Assumes that 'dataValid.txt' contains only valid vectors for now.
bool verifyVector(string record, vector<vector<int>>& vec, int& row, int& col);

// PRE: Accepts a valid 2D vector that has been loaded with proper values
// POST: Prints the output of this vector neatly using setw from iomanip.
void printVector(vector<vector<int>> vec);

// PRE: Accepts a 2D vector that has been loaded with proper values and has the same number
// of rows and columns (square matrix).
// POST: Determines if the vector is reflexive or symmetric and prints the results.
void processVector(vector<vector<int>> vec);

// PRE: Accepts two matrices (2D vectors) that have the same number of rows and columns.
// POST: Adds the two matrices together and prints the result. Prints an error message if 
// the matrices cannot be added due to size mismatch.
void addTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2);

// PRE: Accepts two matrices (2D vectors) where the number of columns in the first matrix 
// is equal to the number of rows in the second matrix.
// POST: Multiplies the two matrices and prints the result. Prints an error message if 
// the matrices cannot be multiplied due to size mismatch.
void multiplyTwoMatrices(vector<vector<int>> vec1, vector<vector<int>> vec2);
