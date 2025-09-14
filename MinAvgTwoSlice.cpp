#include <limits>

int solution(std::vector<int>& values) {
    int N = values.size();
    std::vector<int> sum_list(N, 0);
    for (int i=0; i<N; ++i) {
        int value = values[i];
        if (i == 0) {
            sum_list[i] = value;
        } else {
            sum_list[i] = value + sum_list[i-1];
        }
    }

    double min = std::numeric_limits<double>::max();
    int result = -1;
    for (int i=0; i<N; ++i) {
        int value = values[i];
        for (int j=i+1; j<i+3; ++j) {
            if (j < N) {
                double avg = (sum_list[j] - sum_list[i] + value) * 1.0 / (j-i+1);
                if (avg < min) {
                    result = i;
                    min = avg;
                }
            }            
        }
    }
    return result;
}






