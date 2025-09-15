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

int solution(std::vector<int>& A) {
    int N = A.size();
    std::unordered_set<int> peaks{};
    for (int i=1; i<N-1; ++i) {
        if (A[i]>A[i-1] && A[i]>A[i+1]) {
            peaks.emplace(i);
        }
    }

    std::vector<int> factors{};
    int cursor = 1;
    while (cursor * cursor < N) {
        if (N % cursor == 0) {
            factors.push_back(cursor);
            factors.push_back(N / cursor);
        }
        ++cursor;
    }
    if (cursor * cursor == N) {
        factors.push_back(cursor);
    }
    std::sort(factors.begin(), factors.end(), std::greater<int>{});

    for (int factor : factors) {
        bool pass = true;
        int batch = N / factor;
        for (int i=0; i<N; i=i+batch) {
            bool find = false;
            for (int j=0; j<batch; ++j) {
                int index = i + j;
                if (peaks.contains(index)) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                pass = false;
                break;
            }
        }
        if (pass) {
            return factor;
        }
    }
    return 0;
}






