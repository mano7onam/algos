#pragma warning (disable : 4996)

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int C = 5032107 + 1;
int lp[C]; // least prime divisor
int fred[C];
int num_primes[C];
vector<int> pr;

vector<int> get_divisors(int n) {
    vector<int> divs = {1};
    while (n > 1) {
        int p = lp[n];
        n /= p;
        int sz = divs.size();
        for (int i = 0; i < sz; ++i) {
            divs.push_back(divs[i] * p);
        }
    }
    sort(divs.begin(), divs.end());
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
    return divs;
}

void precalc_lp() {
    for (int i = 2; i < C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < C; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

int main() {
    precalc_lp();
    auto divs = get_divisors(25 * 26 * 27);
    for (auto d : divs) cout << d << '\n';
    return 0;
}

