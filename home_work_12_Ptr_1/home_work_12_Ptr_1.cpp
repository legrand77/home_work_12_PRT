﻿#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix>  clone() {
      auto ptr = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);//std::unique_ptr<tridiagonal_matrix> ptr(new tridiagonal_matrix(m_down, m_upper, m_middle));
      return ptr;
    };
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    for (auto i : matrix->m_down) {
        std::cout << i << std::endl;
    }
    for (auto i : matrix->m_upper) {
        std::cout << i << std::endl;
    }
    for (auto i : matrix->m_middle) {
        std::cout << i << std::endl;
    }
    for (auto i: matrix_clone->m_down){
        std::cout << i << std::endl;
    }
    for (auto i : matrix_clone->m_upper) {
        std::cout << i << std::endl;
    }
    for (auto i : matrix_clone->m_middle) {
        std::cout << i << std::endl;
    }
    return 0;
}