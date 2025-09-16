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
    std::vector<int>results(N, 0);
    for (int i=N-1; i>=0; --i) {
        if (i == N-1) {
            results[i] = A[i];
        } else {
            int result = std::numeric_limits<int>::min();
            for (int j=1; j<=6; ++j) {
                int index = i + j;
                if (index < N) {
                    result = std::max(result, A[i] + results[index]);
                }
            }
            results[i] = result;
        }
    }
    return results[0];
}






