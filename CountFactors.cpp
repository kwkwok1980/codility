int solution(int N) {
    int count = 0;
    int cursor = 1;
    while (cursor * cursor < N) {
        if (N % cursor == 0) {
            count = count + 2;
        }
        ++cursor;
    }
    if (cursor * cursor == N) {
        ++count;
    }
    return count;
}
