#include "util.h"
#include <lazycsv.hpp>
#include <string>
#include <iomanip>

GaussMatrix load_csv_to_matrix(const char *filename) {
    std::vector<std::vector<double>> rows;
    lazycsv::parser parser(filename);
    for (const auto& row : parser) {
        std::vector<double> r;
        for (const auto& cell : row) {
            r.push_back(std::stod(std::string(cell.raw())));
        }
        rows.push_back(r);
    }
    if (rows.empty()) return GaussMatrix();
    GaussMatrix matrix(rows.size(), rows[0].size());
    for (size_t i = 0; i < rows.size(); ++i)
        for (size_t j = 0; j < rows[i].size(); ++j)
            matrix(i, j) = rows[i][j];
    return matrix;
}

void print_matrix_as_csv(std::ostream& out, const GaussMatrix &matrix, int prec) {
    out << std::fixed << std::setprecision(prec);
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            if (j > 0) out << ',';
            out << matrix(i, j);
        }
        out << '\n';
    }
}