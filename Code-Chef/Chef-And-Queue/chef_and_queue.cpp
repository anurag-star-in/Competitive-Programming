/*
 * Problem Statement: https://www.codechef.com/LRNDSA02/problems/CHFQUEUE
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstdio>

typedef unsigned long long ull_t;
typedef long long ll_t;

#define FAST_IO(value) std :: ios :: sync_with_stdio(value); std :: cin.tie(NULL)
#define MOD 1000000007 // Constant (prime number) used in most competitive programming problems to reduce the answer to a 32-bit integer.
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

static ll_t compute_total_fearfullness(const int);

int main(void) {
    FAST_IO(0);
    int n, k;
    std :: cin >> n >> k;
    std :: cout << compute_total_fearfullness(n) << std :: endl;
    return 0;
}

static ll_t compute_total_fearfullness(const int n) {
    std :: stack <std :: pair <int, int>> s;
    ll_t product = 1;
    for(int i = 0; i < n; ++i) {
        int read_value;
        std :: cin >> read_value;
        while(!s.empty() && read_value < s.top().second) {
            product = product * ((i - s.top().first) + 1) % MOD;
            s.pop();
        }
        s.push(std :: make_pair(i, read_value));
    }
    return product;
}
