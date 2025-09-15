#include <limits>
int solution(std::vector<int>& A) {
    int N = A.size();
    std::vector<int> results(N, 0);
    int result = std::numeric_limits<int>::min();
    for (int i=0; i<N; ++i) {
        int value = A[i];
        if (i ==0) {
            int slice = value;
            result = std::max(result, slice);
            results[i] = slice;
        } else {
            int slice = std::max(value, results[i-1] + value);
            result = std::max(result, slice);
            results[i] = slice;
        }
    }
    return result;
}
