#include <gtest/gtest.h>
#include <random>
#include "Gauss_solve.h"

TEST(GaussSolve, SmallSolve)
{
    GaussMatrix ab(3, 4);
    ab << 2, 1, -1, 8,
    -3, -1, 2, -11,
    -2, 1, 2, -3;

    GaussVector x = Gauss_solve(ab);
    ASSERT_EQ(x.size(), 3);
    EXPECT_NEAR(x(0), 2.0, 1e-9);
    EXPECT_NEAR(x(1), 3.0, 1e-9);
    EXPECT_NEAR(x(2), -1.0, 1e-9);
}

TEST(GaussSolve, LargeSystem)
{
    const int n = 50;
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> dis(-10.0, 10.0);

    GaussVector x_true(n);
    for (int i = 0; i < n; ++i) x_true(i) = dis(gen);

    GaussMatrix ab(n, n + 1);
    for (int i = 0; i < n; ++i)
    {
        double row_sum = 0.0;
        for (int j = 0; j < n; ++j)
        {
            ab(i, j) = dis(gen);
            if (i == j) ab(i, j) += 100.0;
            row_sum += ab(i, j) * x_true(j);
        }
        ab(i, n) = row_sum;
    }

    GaussVector x_calc = Gauss_solve(ab);
    for (int i = 0; i < n; ++i)
    {
        EXPECT_NEAR(x_calc(i), x_true(i), 1e-7);
    }
}