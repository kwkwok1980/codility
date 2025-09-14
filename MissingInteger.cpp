#include <algorithm>
#include <limits>
#include <unordered_map>

int solution(std::vector<int>& values) {
    std::unordered_map<int, int> result_map{};
    for (int value : values) {
        if (value >= 1) {
            result_map[value] = 1;    
        }
    }
    int result = 1;
    while (true){
        if(auto it = result_map.find(result); it == result_map.end()) {
            return result;
        }
        ++result;
    }
}
