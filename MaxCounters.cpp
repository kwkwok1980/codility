std::vector<int> solution(int N, std::vector<int>& values) {
    std::vector<int> results (N, 0);
    int max = 0;
    for (int value : values) {
        if (value == (N+1)) {
            std::fill(results.begin(), results.end(), max);
        } else {
            int index = value - 1;
            results[index] = results[index] + 1;
            max = std::max(max, results[index]);
        }
    }
    return results;
}
