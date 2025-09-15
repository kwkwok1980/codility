#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>

std::vector<int> solution(std::vector<int>& A, std::vector<int>& B) {
    int max_a = *std::max_element(A.begin(), A.end());
    int max_b = *std::max_element(B.begin(), B.end());
    int max_mod = (1 << max_b);
    std::unordered_map<int, int> results_map{};
    results_map[1] = 1 % max_mod;
    results_map[2] = 2 % max_mod;
    for (int i=3; i<=max_a; ++i) {
        results_map[i] = (results_map[i-1] + results_map[i-2]) % max_mod;
    }

    int L = A.size();
    std::vector<int> results_list(L, 0);
    for (int i=0; i<L; ++i) {
        int a = A[i];
        int b = B[i];
        int mod = (1 << b);
        int result = results_map[a] % mod;
        results_list[i] = result;
    }
    return results_list;
}
