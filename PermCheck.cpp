int solution(std::vector<int>& values) {
    std::unordered_map<int, int> value_map{};
    int N = values.size();
    for (int value : values) {
        if (value > N) {
            return 0;
        }
        ++value_map[value];
        if (value_map[value] > 1) {
            return 0;
        }
    }
    return 1;
}
