#include "Gauss_solve.h"
#include <stdexcept>
#include <cmath>

GaussVector Gauss_solve(GaussMatrix &ab) {
    int n = ab.rows();
    if (n == 0) return GaussVector();
    int m = ab.cols();
    if (m != n + 1) {
        throw std::runtime_error("Расширенная матрица должна иметь n строк и n+1 столбцов");
    }

    for (int col = 0; col < n; ++col) {
        int maxRow = col;
        double maxVal = std::abs(ab(col, col));
        for (int row = col + 1; row < n; ++row) {
            if (std::abs(ab(row, col)) > maxVal) {
                maxVal = std::abs(ab(row, col));
                maxRow = row;
            }
        }
        if (maxVal < 1e-12) {
            throw std::runtime_error("Матрица вырождена");
        }
        if (maxRow != col) {
            ab.row(col).swap(ab.row(maxRow));
        }

        double pivot = ab(col, col);
        ab.row(col) /= pivot;

        for (int row = 0; row < n; ++row) {
            if (row != col) {
                double factor = ab(row, col);
                if (factor != 0.0) {
                    ab.row(row) -= factor * ab.row(col);
                }
            }
        }
    }

    GaussVector x(n);
    for (int i = 0; i < n; ++i) {
        x(i) = ab(i, n);
    }
    return x;
}