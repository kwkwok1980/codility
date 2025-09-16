#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>

int solution(std::vector<int>& A) {
    int N = A.size();
    std::sort(A.begin(), A.end());
    int result = 0;
    for (int i=2; i<N; ++i) {
        for (int j=i-1; j>=0; --j) {
            int count = 0;
            for (int k=j-1; k >= 0; --k) {
                if (A[k] + A[j] > A[i]) {
                    ++count;
                } else {
                    break;
                }
            }
            result = result + count;
            if (count == 0) {
                break;
            }
        }
    }
    return result;
}
