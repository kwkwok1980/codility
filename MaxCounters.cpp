std::vector<int> solution(int N, std::vector<int>& values) {
    int max = 0;
    int last = 0;
    std::unordered_map<int, int> result_map{};
    for (int value : values) {
        if (value == (N+1)) {
            result_map.clear();
            last = max;
        } else {
            if (auto it = result_map.find(value); it != result_map.end()) {
                int& result = it->second;
                ++result;
                max = std::max(result, max);
            } else {
                int result = last + 1;
                result_map[value] = result;
                max = std::max(result, max);
            }
        }
    }
    std::vector<int> result_list (N, last);
    for (auto [k, v] : result_map) {
        result_list[k-1] = v;
    }
    return result_list;
}
