// Copyright (c) 2021 Sota Tsuji
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include "../include/calculate_km.hpp"

#include <numeric>

#include "../include/graph.hpp"

using namespace std;

Polynomial operator-(Polynomial pol) {
    for (auto& p : pol) {
        p = -p;
    }
    return pol;
}

Polynomial operator/(const Polynomial& pol1, const Polynomial& pol2) {
    return get<0>(polynomial_division(pol1, pol2));
}

Polynomial operator/(Polynomial pol, const Bint x) {
    for (auto& p : pol) {
        p /= x;
    }
    return pol;
}

// Algorithm 8
Bint get_maximum_coefficient(const int n) {
    const int r = (n + 1) / 2;
    const int lambda_max = 2 * (n - 1);
    Bint c_n = 1;
    Bint c_d = 1;
    Bint s = 1;
    for (auto i = 1; i <= r; ++i) {
        c_n *= (n - i + 1);
        c_d *= i;
        s *= lambda_max;
    }
    return s * c_n / c_d;
}

// Algorithm 9
vector<int> get_prime_list(const int n, const Bint c) {
    const auto primes = sieve_of_Eratosthenes(4 * n * n - 1);
    Bint s = 1;
    vector<int> prime_list;
    for (auto i = primes.size() - 1; i >= 0; --i) {
        int p_i = primes[i];
        s *= p_i;
        prime_list.push_back(p_i);
        if (s > 2 * c) {
            break;
        }
    }
    return prime_list;
}

// Algorithm 11
tuple<Polynomial, Polynomial, Bint> polynomial_division(Polynomial f,
                                                        const Polynomial& g) {
    const int n = f.size() - 1, m = g.size() - 1;
    Polynomial q(n - m + 1);
    Bint c = 1;
    for (auto i = n; i >= m; --i) {
        const Bint c_ = g[m] / gcd(f[i], g[m]);
        for (auto j = n; j > i; --j) {
            q[j - m] *= c_;
        }
        for (auto j = 0; j <= i; ++j) {
            f[j] *= c_;
        }
        c *= c_;
        q[i - m] = f[i] / g[m];
        f[i] = 0;
        for (auto j = 1; j <= m; ++j) {
            f[i - j] -= q[i - m] * g[m - j];
        }
    }
    while (!f.empty() && f.back() == 0) {
        f.pop_back();
    }
    return {q, f, c};
}

// Algorithm 12
int get_number_of_roots(Polynomial f) {
    int km = 0;
    while (true) {
        const auto f_ = differential(f);
        const auto r = gcd(f, f_);
        if (r.size() <= 1) {
            km += get_number_of_roots_by_strum(f);
            return km;
        }
        km += get_number_of_roots_by_strum(f / r);
        f = r;
    }
}

vector<int> sieve_of_Eratosthenes(const int k) {
    vector<int> primes(k - 1);
    iota(primes.begin(), primes.end(), 2);
    for (auto i = 0;; ++i) {
        auto itr = primes.begin() + i;
        const int divisor = *itr;
        if (divisor * divisor > k) {
            break;
        }
        ++itr;
        while (itr != primes.end()) {
            if ((*itr) % divisor == 0) {
                itr = primes.erase(itr);
            } else {
                ++itr;
            }
        }
    }
    return primes;
}

Matrix get_double_adjacent_matrix(const WeightedGraph& S) {
    const auto n = S.v.size();
    Matrix A(n, vector<int>(n));
    for (auto i = 0; i < n - 1; ++i) {
        for (auto j = i + 1; j < n; ++j) {
            if (S.e.contains({S.v[i], S.v[j]})) {
                A[i][j] = A[j][i] = 2 / S.rw.at({S.v[i], S.v[j]});
            }
        }
    }
    return A;
}

Polynomial differential(const Polynomial& f) {
    Polynomial f_;
    for (auto i = 1; i < f.size(); ++i) {
        f_.push_back(f[i] * i);
    }
    return f_;
}

Polynomial simplify_coefficient(const Polynomial& f) {
    if (f.size() == 1) {
        return Polynomial(1, 1);
    } else {
        Bint _gcd = gcd(f[0], f[1]);
        for (auto i = 2; i < f.size(); ++i) {
            _gcd = gcd(_gcd, f[i]);
        }
        return f / ((f.back() > 0 ? 1 : -1) * _gcd);
    }
}

Polynomial gcd(Polynomial f, Polynomial g) {
    if (f.size() < g.size()) {
        tie(f, g) = {g, f};
    }
    while (true) {
        auto [_q, r, _c] = polynomial_division(f, g);
        if (r.empty()) {
            return simplify_coefficient(g);
        }
        tie(f, g) = {g, r};
    }
}

Polynomial rem(const Polynomial& f, const Polynomial& g) {
    return get<1>(polynomial_division(f, g));
}

Bint substitute_into_polynomial(const Polynomial& f, const int x) {
    Bint power = 1;
    Bint n = 0;
    for (auto i = 0; i < f.size(); ++i) {
        n += f[i] * power;
        power *= x;
    }
    return n;
}

int sigma(const vector<Polynomial>& fs, const int alpha) {
    int count_of_sign_changes = 0;
    int prev_sign = 0;
    int i;
    for (i = 0; i < fs.size() && prev_sign == 0; ++i) {
        const Bint sigma_alpha = substitute_into_polynomial(fs[i], alpha);
        prev_sign = sigma_alpha == 0 ? 0 : (sigma_alpha > 0 ? 1 : -1);
    }
    for (auto j = i; j < fs.size(); ++j) {
        const Bint sigma_alpha = substitute_into_polynomial(fs[j], alpha);
        const int current_sign =
            sigma_alpha == 0 ? 0 : (sigma_alpha > 0 ? 1 : -1);
        if (current_sign == -prev_sign) {
            ++count_of_sign_changes;
            prev_sign = current_sign;
        }
    }
    return count_of_sign_changes;
}

int sigma(const vector<Polynomial>& fs, const Infinity inf) {
    bool is_positive = inf == Infinity::Positive;
    int count_of_sign_changes = 0;
    int prev_sign =
        fs[0].back() * ((is_positive || fs[0].size() % 2 == 1) ? 1 : -1) > 0
            ? 1
            : -1;
    for (auto i = 1; i < fs.size(); ++i) {
        const int current_sign =
            fs[i].back() * ((is_positive || fs[i].size() % 2 == 1) ? 1 : -1) > 0
                ? 1
                : -1;
        if (current_sign == -prev_sign) {
            ++count_of_sign_changes;
            prev_sign = current_sign;
        }
    }
    return count_of_sign_changes;
}

int get_number_of_roots_by_strum(const Polynomial& f) {
    vector<Polynomial> ps;
    ps.push_back(f);
    if (f.size() > 1) {
        ps.push_back(differential(f));
        for (auto j = 2; ps.back().size() > 1; ++j) {
            ps.push_back(-rem(ps[j - 2], ps[j - 1]));
        }
    }
    return sigma(ps, Infinity::Negative) - sigma(ps, -2);
}
