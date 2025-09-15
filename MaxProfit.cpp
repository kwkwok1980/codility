int solution(std::vector<int>& A) {
    if (A.empty()) return 0;
    int min = A[0];
    int result = 0;
    for (int value : A) {
        if (value > min) {
            result = std::max(result, value - min);
        } else {
            min = value;
        }
    }
    return result;
}
