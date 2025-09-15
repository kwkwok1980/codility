#include <math.h>

int solution(std::vector<int>& A) {
    std::vector<int> peaks{};
    int N = A.size();
    for (int i=1; i<N-1; ++i) {
        if (A[i]>A[i-1] && A[i]>A[i+1]) {
            peaks.push_back(i);
        }
    }

    int N1 = peaks.size();
    int N2 = std::sqrt(N) + 1;
    int N3 = std::min(N1, N2);
    for (int i=N3; i>=1; --i) {
        int last = -1;
        int count = i;
        for (int j=0; j<N1; ++j) {
            int peak = peaks[j];
            if (j == 0) {
                last = peak;
                --count;
            } else {
                if (peak - last >= i) {
                    last = peak;
                    --count;
                }
            }
            if (count == 0){
                return i;
            }
        }
    }
    return 0;

}






