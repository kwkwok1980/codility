#include <unordered_map>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <ostream>
#include <vector>
#include <list>
#include <queue>

int solution(std::vector<int>& A) {
    std::stack<int> values{};
    for (int value : A) {
        if (values.empty()) {
            values.push(value);
        } else {
            if (value != values.top()) {
                values.pop();
            } else {
                values.push(value);
            }
        }
    }
    if (!values.empty()) {
        int N = A.size();
        int index = -1;
        int count = 0;
        for (int i=0; i<N; ++i) {
            if (A[i] == values.top()) {
                index = i;
                ++count;
            }
        }
        if (count > N/2) {
            return index;
        }
    }
    return -1;
}
