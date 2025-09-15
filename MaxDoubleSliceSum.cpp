#include <unordered_map>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <ostream>
#include <vector>
#include <list>
#include <queue>

int solution(std::vector<int>& A) {
    int N = A.size();
    std::vector<int> results1(N, 0);
    for (int i=0; i<N; ++i) {
        int value = A[i];
        if (i == 0){
            results1[i] = 0;
        } else {
            results1[i] = std::max(value, value + results1[i-1]);
        }
    }
    std::vector<int> results2(N, 0);
    for (int i=N-1; i>=0; --i) {
        int value = A[i];
        if (i == N-1) {
            results2[i] = 0; 
        } else {
            results2[i] = std::max(value, value + results2[i+1]);
        }
    }
    int result = std::numeric_limits<int>::min();
    for (int i=1; i<N-1; ++i) {
        if (i == 1) {
            result = std::max(result, std::max(0, results2[i+1]));
        } else if (i == N-2) {
            result = std::max(result, std::max(0, results1[i-1]));
        } else {
            result = std::max(result, std::max(0, results1[i-1]) + std::max(0,results2[i+1]));
        }
    }
    return result;
}
