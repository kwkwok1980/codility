#include <limits>


int solution(int N) {
    int result = std::numeric_limits<int>::max();
    int cursor = 1;
    while (cursor * cursor <= N) {
        if (N % cursor == 0) {
            int A = cursor;
            int B = N / cursor;
            result = std::min(result, 2*(A+B));
        }
        ++cursor;
    }
    return result;
}
