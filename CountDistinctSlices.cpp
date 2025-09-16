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

int solution(int M, std::vector<int>& A) {
    std::unordered_set<int> seen_set{};
    int N = A.size();
    int cursor = 0;
    int result = 0;
    for (int i=0; i<N; ++i) {
        while (cursor < N) {
            int a = A[cursor];
            if (auto [it, inserted] = seen_set.emplace(a); inserted) {
                ++cursor;
            } else {
                break;
            }
        }
        result = result + (cursor - i);
        if (result > 1000000000) {
            return 1000000000;
        }
        seen_set.erase(A[i]);
    }
    return result;
}
