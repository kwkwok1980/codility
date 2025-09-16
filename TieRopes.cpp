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

int solution(int K, std::vector<int>& A) {
    int count = 0;
    int length = 0;
    for (int value : A) {
        length = length + value;
        if (length >= K) {
            ++count;
            length = 0;
        }
    }
    return count;
}
