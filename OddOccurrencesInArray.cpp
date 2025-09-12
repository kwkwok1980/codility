#include <unordered_map>

int solution(vector<int>& values) {
    std::unordered_map<int, int> values_map{};
    for (int value : values) {
        ++values_map[value];
    }
    for (auto [value, count] : values_map) {
        if ((count % 2) != 0) {
            return value;
        }
    }
    return 0;
}
