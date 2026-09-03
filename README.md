Overview:

A math utility written in C++ that computes the solution vector for a system of N linear equations. The program manually manages two-dimensional arrays via pointers and implements the standard Gaussian elimination algorithm natively, without relying on external linear algebra libraries. It includes precision-based safety checks (detecting values near zero) during row operations to warn users if the coefficient matrix is singular.

Operation:

the application operates via a sequential console prompt. The user first defines the system size (N), followed by manually inputting the coefficients for the N x N matrix and the N x 1 constant vector. The algorithm runs forward elimination to form an upper triangular matrix, then applies backward substitution to solve for the variables. The results are printed to the console formatted to four decimal places, and all dynamically allocated memory is securely freed before termination.# Gaussian-Elimination-Linear-Solver
C++ application that solves systems of linear equations (Ax = B) using the Gaussian elimination algorithm. It dynamically allocates memory for user-defined N x N matrices and processes data through forward elimination, backward substitution, and basic singularity detection.
