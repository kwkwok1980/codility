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
    std::unordered_map<int, int> count_map{};
    int N = A.size();
    int leader = -1;
    for (int value : A) {
        int &count = count_map[value];
        ++count;
        if (count > N / 2) {
            leader = value;
            break;
        }
    }
    if (leader == -1) {
        return 0;
    }
    
    std::vector<int> count_list(N, 0);
    int count = 0;
    for (int i=0; i<N; ++i) {
        int value = A[i];
        if (value == leader) {
            ++count;
        }
        count_list[i] = count;
    }

    int result = 0;
    for (int i=0; i<N-1; ++i) {
        int c1 = count_list[i];
        int c2 = count_list[N-1] - count_list[i];
        if (c1 > (i+1)/2 && c2 > (N-i-1)/2) {
            ++result;
        }
    }
    return result;
}
