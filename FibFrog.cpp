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
    std::unordered_set<int> fib_set{};
    std::vector<int> fib_list{};
    int f0 = 0;
    int f1 = 1;
    int f2 = 0;
    do {
        f2 = f1 + f0;
        fib_set.emplace(f2);
        fib_list.push_back(f2);
        f0 = f1;
        f1 = f2;
    } while (f2 <= N);
    
    std::vector<int> counts (N+1, -1);
    for (int i=0; i<N+1; ++i) {
        if (i == N || A[i] == 1) {
            int fib = i + 1;
            if (fib_set.contains(fib)) {
                counts[i] = 1;
            }
        }
    }
    
    for (int i=0; i<N+1; ++i) {
        if (i == N || A[i] == 1) {
            if (counts[i] == -1) {
                int min = std::numeric_limits<int>::max();
                for(int fib : fib_list) {
                    int j = i - fib;
                    if (j > -1) {
                        if (A[j] == 1) {
                            if (counts[j] > 0) {
                                min = std::min(min, counts[j] + 1);
                            }
                        }
                    } else {
                        break;
                    }
                }
                if (min != std::numeric_limits<int>::max()) {
                    counts[i] = min;
                }
            }
        }
    }
    
    return counts[N];
}
