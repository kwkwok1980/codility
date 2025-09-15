#include <unordered_map>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <ostream>
#include <vector>
#include <list>
#include <queue>

int solution(std::vector<int>& H) {
    std::stack<int> block_list{};
    int N = H.size();
    int result = 0;
    block_list.push(H[0]);
    int current = H[0];
    for (int i=0; i<N; ++i) {
        int h = H[i];
        if (h > current) {
            h = h - current;
            block_list.push(h);
        } else if (h == current) { 
            // pass            
        } else {
            while (current > h) {
                current = current - block_list.top();
                block_list.pop();
                ++result;
            }
            h = h - current;
            if (h > 0) {
                block_list.push(h);
            }
        }
        current = H[i];
    }
    result = result + block_list.size();
    return result;
}
