#include <unordered_map>

int solution(std::vector<int>& A) {
    std::unordered_map<int, int> results{};
    for (int value : A) {
        ++results[value];
    }
    int N = A.size();
    int D = N/2;
    for (int i=0; i<N; ++i) {
        int value = A[i];
        if (results[value] > D) {
            return i;
        }
    }    
    return -1;
}
