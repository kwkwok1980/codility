#include <unordered_map>
#include <limits>

int solution(std::vector<int>& values) {
    
    std::unordered_map<int, int> values_map{};
    for (int value : values) {
        values_map[value] = 1;
    }
    return values_map.size();
}
