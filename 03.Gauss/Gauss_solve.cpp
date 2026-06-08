#include "Gauss_solve.h"
#include <cmath>

GaussVector Gauss_solve(GaussMatrix &ab)
{
    int n = ab.rows();
    int m = ab.cols();

    for (int i = 0; i < n; ++i)
    {
        int max_row = i;
        for (int k = i + 1; k < n; ++k)
        {
            if (std::abs(ab(k, i)) > std::abs(ab(max_row, i)))
            {
                max_row = k;
            }
        }
        if (max_row != i)
        {
            ab.row(i).swap(ab.row(max_row));
        }

        for (int j = i + 1; j < n; ++j)
        {
            double factor = ab(j, i) / ab(i, i);
            ab.row(j).tail(m - i) -= factor * ab.row(i).tail(m - i);
        }
    }

    GaussVector x(n);
    for (int i = n - 1; i >= 0; --i)
    {
        double sum = 0.0;
        if (i < n - 1)
        {
            int len = n - 1 - i;
            sum = ab.row(i).segment(i + 1, len).dot(x.segment(i + 1, len));
        }
        x(i) = (ab(i, n) - sum) / ab(i, i);
    }
    return x;
}