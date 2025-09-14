int solution(std::vector<int>& values) {
    int sum = 0;
    for (int value : values) {
        sum = sum + value;
    }
    int sum1 = 0;
    int sum2 = sum;
    int N = values.size();
    int result = std::numeric_limits<int>::max();
    for (int i=1; i<N; ++i) {
        int value = values[i-1];
        sum1 = sum1 + value;
        sum2 = sum2 - value;
        result = std::min(result, std::abs(sum2 - sum1));
    }
    return result;
}
