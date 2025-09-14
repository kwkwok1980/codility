#include <algorithm>
#include <limits>
#include <unordered_map>

int solution(int X, std::vector<int>& values) {
    std::unordered_map<int, int> value_map{};
    int N = values.size();
    for (int i=0; i<N; ++i) {
        int value = values[i];
        if (value <= X) {
            value_map[value] = 1;
            if (value_map.size() == X) {
                return i;
            }
        }
    }
    return -1;
}
