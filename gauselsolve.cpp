#include <iostream>
#include <iomanip>
#include <cmath>

void getInput(int N, double** A, double* B);
bool gaussianElimination(int N, double** A, double* B, double* X);
void printSolution(int N, const double* X);
void cleanup(int N, double** A, double* B, double* X);

int main() {
    std::cout << std::fixed << std::setprecision(4);

    int N;
    std::cout << "--- Gaussian Elimination Solver ---\n";
    std::cout << "Enter the number of equations (N): ";

    if (!(std::cin >> N) || N <= 0) {
        std::cerr << "Invalid input. Please enter a positive integer for N.\n";
        return 1;
    }

    double** A = new double* [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new double[N];
    }
    double* B = new double[N];
    double* X = new double[N];

    getInput(N, A, B);

    bool success = gaussianElimination(N, A, B, X);

    if (success) {
        printSolution(N, X);
    }
    else {
        std::cerr << "\n[WARNING]: The system cannot be solved (Division by zero detected).\n";
        std::cerr << "This typically indicates that the coefficient matrix is singular.\n";
    }

    cleanup(N, A, B, X);

    return 0;
}

void getInput(int N, double** A, double* B) {
    std::cout << "\nEnter the coefficients a[i][j] for the N x N matrix A:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "a[" << i << "][" << j << "]: ";
            if (!(std::cin >> A[i][j])) {
                std::cerr << "Input error. Exiting.\n";
                exit(1);
            }
        }
    }

    std::cout << "\nEnter the constants b[i] for the N x 1 vector B:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "b[" << i << "]: ";
        if (!(std::cin >> B[i])) {
            std::cerr << "Input error. Exiting.\n";
            exit(1);
        }
    }
}

bool gaussianElimination(int N, double** A, double* B, double* X) {

    for (int k = 0; k <= N - 2; ++k) {

        if (std::abs(A[k][k]) < 1e-9) {
            return false;
        }

        for (int i = k + 1; i <= N - 1; ++i) {

            double m = A[i][k] / A[k][k];

            for (int j = k; j <= N - 1; ++j) {
                A[i][j] = A[i][j] - m * A[k][j];
            }

            B[i] = B[i] - m * B[k];
        }
    }

    if (std::abs(A[N - 1][N - 1]) < 1e-9) {
        return false;
    }

    X[N - 1] = B[N - 1] / A[N - 1][N - 1];

    for (int k = N - 2; k >= 0; --k) {
        double sum = 0.0;

        for (int j = k + 1; j <= N - 1; ++j) {
            sum = sum + A[k][j] * X[j];
        }

        if (std::abs(A[k][k]) < 1e-9) {
            return false;
        }
        X[k] = (B[k] - sum) / A[k][k];
    }

    return true;
}

void printSolution(int N, const double* X) {
    std::cout << "\n--- Solution Vector X ---\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "x[" << i << "] = " << X[i] << std::endl;
    }
    std::cout << "-------------------------\n";
}

void cleanup(int N, double** A, double* B, double* X) {
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    delete[] B;
    delete[] X;

    A = nullptr;
    B = nullptr;
    X = nullptr;
}