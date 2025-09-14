#include <algorithm>
#include <limits>
#include <unordered_map>

int solution(std::vector<int>& values) {
    int count = 0;
    int result = 0;
    for (int value : values) {
        if (value == 1) {
            ++count;
        }
    }
    int N = values.size();
    for (int i=0; i<N; ++i) {
        int value = values[i];
        if (value == 0) {
            result = result + count;
        } else {
            --count;
        }
    }
    return result;
}
