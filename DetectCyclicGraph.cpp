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

bool solution(std::vector<int>&A, std::vector<int> &B) {
    int N = A.size();
    std::unordered_map<int, int> lines_map{};
    for (int i=0; i<N; ++i) {
        lines_map[A[i]] = B[i];
    }
    if (lines_map.size()!= N) {
        return false;
    }
    int begin = A[0];
    int cursor = begin;
    int count = 0;
    while (true) {
        cursor = lines_map[cursor];
        ++count;
        if (cursor == begin) {
            break;
        }
        if (count > N) {
            break;
        }
    }
    return count == N;
}
