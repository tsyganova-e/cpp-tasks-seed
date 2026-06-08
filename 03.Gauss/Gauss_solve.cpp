#include <iostream>
#include <string>
#include "util.h"
#include "Gauss_solve.h"

int main(int argc, const char *argv[])
{
    if (argc < 2) return 1;

    auto ab = load_csv_to_matrix(argv[1]);
    if (ab.rows() == 0) return 1;

    GaussVector x = Gauss_solve(ab);

    GaussMatrix x_mat(x.size(), 1);
    for (int i = 0; i < x.size(); ++i)
    {
        x_mat(i, 0) = x(i);
    }

    print_matrix_as_csv(std::cout, x_mat, 6);

    return 0;
}