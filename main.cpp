#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    std::ifstream inputFile("./test_cases/Sample_test/Test_2/input_matrix.txt");
    if (!inputFile) {
        cerr << "Unable to open file!";
        return 1;
    }

    string content;

    // Read the first line for settings
    getline(inputFile, content);
    stringstream ss(content);
    vector<int> settings;
    int value;

    while (ss >> value) {
        settings.push_back(value);
    }

    // Ensure the settings array has exactly 4 elements
    if (settings.size() != 4) {
        cerr << "Error: The input does not contain exactly 4 values.";
        return 1;
    }

    // Check the constraints for the settings
    if (settings[0] < 3 || settings[0] > 7 ||
        settings[1] < 2 || settings[1] > 4 ||
        settings[2] < 0 || settings[2] > 4 ||
        settings[3] < 1 || settings[3] > 3) {
        cerr << "Invalid settings values.";
        return 0;
    }

    int matrixSize = settings[0]; // Size of the first matrix (e.g., 3x3)
    int kernelSize = settings[1]; // Size of the kernel matrix (e.g., 2x2 or 4x4)
    int paddingSize = settings[2]; // Size of the padding to add

    // Parse the second line into a matrix of size `matrixSize x matrixSize`
    vector<vector<double>> matrix(matrixSize, vector<double>(matrixSize));
    if (getline(inputFile, content)) {
        stringstream ssRow(content);
        double num;
        int count = 0;

        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                if (ssRow >> num) {
                    matrix[i][j] = num;
                    count++;
                }
            }
        }

        if (count < matrixSize * matrixSize) {
            cerr << "Error: Not enough values to fill the first matrix.";
            return 1;
        }
    } else {
        cerr << "Error: Second line not found.";
        return 1;
    }

    // Parse the third line into a kernel matrix of size `kernelSize x kernelSize`
    vector<vector<double>> kernel(kernelSize, vector<double>(kernelSize));
    if (getline(inputFile, content)) {
        stringstream ssRow(content);
        double num;
        int count = 0;

        for (int i = 0; i < kernelSize; ++i) {
            for (int j = 0; j < kernelSize; ++j) {
                if (ssRow >> num) {
                    kernel[i][j] = num;
                    count++;
                }
            }
        }

        if (count < kernelSize * kernelSize) {
            cerr << "Error: Not enough values to fill the kernel matrix.";
            return 1;
        }
    } else {
        cerr << "Error: Third line not found.";
        return 1;
    }

    inputFile.close();  // Close the file after reading

    // Add padding to the kernel matrix
    int paddedSize = kernelSize + 2 * paddingSize;
    vector<vector<double>> paddedKernel(paddedSize, vector<double>(paddedSize, 0.0));

    for (int i = 0; i < kernelSize; ++i) {
        for (int j = 0; j < kernelSize; ++j) {
            paddedKernel[i + paddingSize][j + paddingSize] = kernel[i][j];
        }
    }

    // Print the first matrix for verification
    cout << "First matrix (" << matrixSize << "x" << matrixSize << "):\n";
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Print the kernel matrix for verification
    cout << "\nKernel matrix (" << kernelSize << "x" << kernelSize << "):\n";
    for (const auto& row : kernel) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Print the padded kernel matrix for verification
    cout << "\nPadded kernel matrix (" << paddedSize << "x" << paddedSize << "):\n";
    for (const auto& row : paddedKernel) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
