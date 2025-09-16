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

int solution_impl(int M, std::vector<int>& A) {
    int count = 1;
    int sum = 0;
    for (int value : A) {
        int temp = sum + value;
        if (temp <= M) {
            sum = temp;
        } else {
            ++count;
            sum = value;
        }
    }
    return count;
}

int solution(int K, int M, std::vector<int>& A) {
    int N = A.size();
    int start = *std::max_element(A.begin(), A.end());
    int end = start * N;
    int mid = 0;
    while (start < end) {
        mid = start + (end - start)/2;
        int k = solution_impl(mid, A);
        if (k < K) {
            end = mid-1;
        } else if (k > K) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    return start;
}






