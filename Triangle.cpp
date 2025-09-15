#include <unordered_map>
#include <limits>
#include <algorithm>

int solution(std::vector<int>& values) {
    std::sort(values.begin(), values.end());
    int N = values.size();
    for (int i=0; i<N-2; ++i) {
        if (values[i] > values[i+2] - values[i+1] ) {
            return 1;
        }
    }    
    return 0;
}
