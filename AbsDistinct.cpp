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
    int count = 0;
    int cursor1 = -1;
    for (int i=0; i<N; ++i) {
        if (A[i] >= 0) {
            cursor1 = i;
            break;
        }
    }
    if (cursor1 == -1 || cursor1 == 0) {
        for (int i=0; i<N-1; ++i) {
            if (A[i] == A[i+1]) {
                ++count;
            }
        }
        return N - count;
    }
    int cursor2 = cursor1 - 1;

    auto advance1 = [&] {
        --cursor1;
        while (true) {
            if (cursor1 > 0) {
                if (A[cursor1] == A[cursor1-1]) {
                    --cursor1;
                    ++count;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    };

    auto advance2 = [&] {
        ++cursor2;
        while (true) {
            if (cursor2 < N-1) {
                if (A[cursor2] == A[cursor2+1]) {
                    ++cursor2;
                    ++count;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    };

    advance1();
    advance2();
    while (cursor1 >= 0 && cursor2 < N) {
        int value1 = std::abs(A[cursor1]);
        int value2 = A[cursor2];
        if (value1 == value2) {
            ++count;
            advance1();
            advance2();
        } else if (value1 > value2) {
            advance2();
        } else {
            advance1();
        }
    }

    return N - count;
}

