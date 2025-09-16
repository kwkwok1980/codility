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
    std::sort(A.begin(), A.end(), std::greater<int>{});
    int result = std::numeric_limits<int>::max();
    int cursor = N-1;
    for (int i=0; i<N; ++i) {
        while (cursor >= i) {
            int temp = A[i] + A[cursor];
            result = std::min(result, std::abs(temp));
            if (temp >= 0) {
                if (cursor < N-1) {
                    cursor = cursor + 1;
                }
                break;
            } else {
                --cursor;
            }
        }
    }
    return result;
}






